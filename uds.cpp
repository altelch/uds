#include "Arduino.h"
#include "iso-tp.h"
#include "uds.h"
#include <mcp_can.h>

void UDS::print_buffer(uint8_t *buffer, uint16_t len)
{
  uint16_t i=0;

  Serial.print(F("Buffer: ")); Serial.print(F(" ["));
  Serial.print(len); Serial.print(F("] "));
  for(i=0;i<len;i++)
  {
    if(buffer[i] < 0x10) Serial.print(F("0"));
    Serial.print(buffer[i],HEX);
    Serial.print(F(" "));
  }
  Serial.println();
}

UDS::UDS(IsoTp* isotp)
{
  _isotp = isotp;
}

uint8_t UDS::Session(Session_t* session)
{
  struct Message_t msg;
  uint32_t timeout=millis();
  uint8_t retry=UDS_RETRY;
  uint8_t retval=0;

  memset(tmpbuf,0,MAX_DATA);
  tmpbuf[0]=session->sid;
  memcpy(tmpbuf+1,session->Data,session->len);
  msg.rx_id=session->rx_id;
  msg.tx_id=session->tx_id;
  msg.len=session->len+1;
  msg.Buffer=tmpbuf;
  while(retval=(_isotp->send(&msg) && retry)) retry--;
  if(!retval) _isotp->receive(&msg);
  if(millis()-timeout >= UDS_TIMEOUT) retval=1;
  if(msg.Buffer[1]==UDS_ERROR_ID)
  {
    retval=UDS_ERROR_ID;
		session->Data=tmpbuf+1;
		session->len=msg.len-1;
    session->nrc=msg.Buffer[3]; // Neg. Resp. Code
  }
  else
  {
    session->Data=tmpbuf+1+session->len; // Return receive msg. - SID and PID
    session->len=msg.len-1-session->len; // Return length of msg. - SID and PID
  }

  return retval;
}

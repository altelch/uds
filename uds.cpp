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

uint16_t UDS::Session(Session_t* session)
{
  struct Message_t msg;
  uint32_t timeout=millis();
  uint8_t retry=UDS_RETRY;
  uint16_t retval=0;

  memset(tmpbuf,0,MAX_DATA);
  tmpbuf[0]=session->sid;
  memcpy(tmpbuf+1,session->Data,session->len);
  msg.rx_id=session->rx_id;
  msg.tx_id=session->tx_id;
  msg.len=session->len+1;
  msg.Buffer=tmpbuf;
  while(retval=(_isotp->send(&msg) && retry)) retry--; // retry on error
  if(!retval) isotp->receive(&msg);                    // if no error receive
  if(millis()-timeout >= UDS_TIMEOUT) retval=1;
  else
  {
    if(msg.Buffer[0]==UDS_ERROR_ID)
    {
      retval=(uint16_t) UDS_ERROR_ID<<8 | msg.Buffer[1];
      session->Data=tmpbuf+1;
      session->len=msg.len-1;
    }
    else
    {
      session->Data=tmpbuf+1+session->len;// Return receive msg. - SID and PID
      session->len=msg.len-1-session->len;// Return length of msg. - SID and PID
    }
  }
  return retval;
}

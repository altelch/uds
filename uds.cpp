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

uint8_t UDS::Diagnostic_Session_Control(Session_t* session)
{
  struct Message_t msg;
  uint8_t tmp[MAX_DATA];
  uint32_t timeout=millis();
  uint8_t retry=UDS_RETRY;
  uint8_t retval=0;

  memset(tmp,0,MAX_DATA);
  tmp[0]=UDS_SID_DIAGNOSTIC_CONTROL;
  memcpy(tmp+1,session->Data,session->len);
  msg.rx_id=session->rx_id;
  msg.tx_id=session->tx_id;
  msg.len=session->len+1;
  msg.Buffer=tmp;
  while(retval=(_isotp->send(&msg) && retry)) retry--;
  if(!retval) _isotp->receive(&msg);
  if(millis()-timeout >= UDS_TIMEOUT) retval=1;

  return retval;
}

uint8_t UDS::ECU_Reset(Session_t* session)
{
}

uint8_t UDS::Security_Access(Session_t* session)
{
}

uint8_t UDS::Communication_Control(Session_t* session)
{
}

uint8_t UDS::Tester_Present(Session_t* session)
{
}

uint8_t UDS::Access_Timing_Parameter(Session_t* session)
{
}

uint8_t UDS::Secured_Data_Transmission(Session_t* session)
{
}

uint8_t UDS::Control_DTC_Settings(Session_t* session)
{
}

uint8_t UDS::Response_On_Event(Session_t* session)
{
}

uint8_t UDS::Link_Controll(Session_t* session)
{
}

uint8_t UDS::Read_Data_By_Identifier(Session_t* session)
{
}

uint8_t UDS::Read_Memory_By_Address(Session_t* session)
{
}

uint8_t UDS::Read_Scaling_Data_By_Identifier(Session_t* session)
{
}

uint8_t UDS::Read_Data_By_Periodic_Identifier(Session_t* session)
{
}

uint8_t UDS::Dynamically_Define_Data_Identifier(Session_t* session)
{
}

uint8_t UDS::Write_Data_By_Identifier(Session_t* session)
{
}

uint8_t UDS::Write_Memory_By_Address(Session_t* session)
{
}

uint8_t UDS::Clear_Diagnostic_Information(Session_t* session)
{
}

uint8_t UDS::Read_DTC_Information(Session_t* session)
{
}

uint8_t UDS::Input_Output_Control_By_Identifier(Session_t* session)
{
}

uint8_t UDS::Routine_Control(Session_t* session)
{
}

uint8_t UDS::Request_Download(Session_t* session)
{
}

uint8_t UDS::Request_Upload(Session_t* session)
{
}

uint8_t UDS::Transfer_Data(Session_t* session)
{
}

uint8_t UDS::Request_Transfer_Exit(Session_t* session)
{
}

uint8_t UDS::Request_File_Transfer(Session_t* session)
{
}


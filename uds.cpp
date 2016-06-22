#include "Arduino.h"
#include "iso-tp.h"
#include "uds.h"
#include <mcp_can.h>

UDS::UDS(IsoTp* isotp)
{
  _isotp = isotp;
}

uint8_t UDS::Diagnostic_Session_Control(Session_t* session)
{
  uint8_t txbuf[]={0x10, 0x00};

  txbuf[1]=session->Data[0];
  struct Message_t TxMsg;
  TxMsg.rx_id=session->rx_id;
  TxMsg.tx_id=session->tx_id;
  TxMsg.Buffer=txbuf;
  _isotp->send(&TxMsg);
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


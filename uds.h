#ifndef _UDS_H
#define _UDS_H

#include <mcp_can.h>
#include <iso-tp.h>

//#define UDS_DEBUG

#define MAX_DATA 128

struct Session_t
{
  uint32_t tx_id=0;
  uint32_t rx_id=0;
  uint8_t *Data;
  uint8_t len=0;
};

class UDS
{
	public:
		UDS(IsoTp* isotp);
		uint8_t Diagnostic_Session_Control(Session_t* msg);
		uint8_t ECU_Reset(Session_t* msg);
		uint8_t Security_Access(Session_t* msg);
		uint8_t Communication_Control(Session_t* msg);
		uint8_t Tester_Present(Session_t* msg);
		uint8_t Access_Timing_Parameter(Session_t* msg);
		uint8_t Secured_Data_Transmission(Session_t* msg);
		uint8_t Control_DTC_Settings(Session_t* msg);
		uint8_t Response_On_Event(Session_t* msg);
		uint8_t Link_Controll(Session_t* msg);
		uint8_t Read_Data_By_Identifier(Session_t* msg);
		uint8_t Read_Memory_By_Address(Session_t* msg);
		uint8_t Read_Scaling_Data_By_Identifier(Session_t* msg);
		uint8_t Read_Data_By_Periodic_Identifier(Session_t* msg);
		uint8_t Dynamically_Define_Data_Identifier(Session_t* msg);
		uint8_t Write_Data_By_Identifier(Session_t* msg);
		uint8_t Write_Memory_By_Address(Session_t* msg);
		uint8_t Clear_Diagnostic_Information(Session_t* msg);
		uint8_t Read_DTC_Information(Session_t* msg);
		uint8_t Input_Output_Control_By_Identifier(Session_t* msg);
		uint8_t Routine_Control(Session_t* msg);
		uint8_t Request_Download(Session_t* msg);
		uint8_t Request_Upload(Session_t* msg);
		uint8_t Transfer_Data(Session_t* msg);
		uint8_t Request_Transfer_Exit(Session_t* msg);
		uint8_t Request_File_Transfer(Session_t* msg);
	private:
		IsoTp* _isotp;
};
#endif

#ifndef _UDS_H
#define _UDS_H

#include <mcp_can.h>
#include <iso-tp.h>

//#define UDS_DEBUG

#define MAX_DATA 128
#define UDS_RETRY 3
#define UDS_TIMEOUT 500
#define UDS_KEEPALIVE 3000

/* UDS SIDs */
#define UDS_SID_DIAGNOSTIC_CONTROL        0x10
#define UDS_SID_ECU_RESET                 0x11
#define UDS_SID_CLEAR_DTC                 0x14
#define UDS_SID_READ_DTC                  0x19
#define UDS_SID_READ_DATA_BY_ID           0x22
#define UDS_SID_READ_MEM_BY_ADDRESS       0x23
#define UDS_SID_READ_SCALING_BY_ID        0x24
#define UDS_SID_SECURITY_ACCESS           0x27
#define UDS_SID_READ_DATA_BY_ID_PERIODIC  0x2A
#define UDS_SID_DEFINE_DATA_ID            0x2C
#define UDS_SID_WRITE_DATA_BY_ID          0x2E
#define UDS_SID_IO_CONTROL_BY_ID          0x2F
#define UDS_SID_ROUTINE_CONTROL           0x31
#define UDS_SID_REQUEST_DOWNLOAD          0x34
#define UDS_SID_REQUEST_UPLOAD            0x35
#define UDS_SID_TRANSFER_DATA             0x36
#define UDS_SID_REQUEST_XFER_EXIT         0x37
#define UDS_SID_REQUEST_XFER_FILE         0x38
#define UDS_SID_WRITE_MEM_BY_ADDRESS      0x3D
#define UDS_SID_TESTER_PRESENT            0x3E
#define UDS_SID_ACCESS_TIMING             0x83
#define UDS_SID_SECURED_DATA_TRANS        0x84
#define UDS_SID_CONTROL_DTC_SETTINGS      0x85
#define UDS_SID_RESPONSE_ON_EVENT         0x86
#define UDS_SID_LINK_CONTROL              0x87

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
		void    print_buffer(uint8_t *buffer, uint16_t len);
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

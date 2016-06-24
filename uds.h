#ifndef _UDS_H
#define _UDS_H

#include <mcp_can.h>
#include <iso-tp.h>

//#define UDS_DEBUG

#define MAX_DATA 128
#define UDS_RETRY 3
#define UDS_TIMEOUT 500
#define UDS_KEEPALIVE 3000

/* OBD-II Modes */
#define OBD_MODE_SHOW_CURRENT_DATA        0x01
#define OBD_MODE_SHOW_FREEZE_FRAME        0x02
#define OBD_MODE_READ_DTC                 0x03
#define OBD_MODE_CLEAR_DTC                0x04
#define OBD_MODE_TEST_RESULTS_NON_CAN     0x05
#define OBD_MODE_TEST_RESULTS_CAN         0x06
#define OBD_MODE_READ_PENDING_DTC         0x07
#define OBD_MODE_CONTROL_OPERATIONS       0x08
#define OBD_MODE_VEHICLE_INFORMATION      0x09
#define OBD_MODE_READ_PERM_DTC            0x0A

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

/* UDS Error Codes */
#define UDS_ERROR_ID                         0x7F
#define UDS_NRC_SUCCESS                      0x00
#define UDS_NRC_SERVICE_NOT_SUPPORTED        0x11
#define UDS_NRC_SUB_FUNCTION_NOT_SUPPORTED   0x12
#define UDS_NRC_INCORRECT_LENGTH_OR_FORMAT   0x13
#define UDS_NRC_CONDITIONS_NOT_CORRECT       0x22
#define UDS_NRC_REQUEST_OUT_OF_RANGE         0x31
#define UDS_NRC_SECURITY_ACCESS_DENIED       0x33
#define UDS_NRC_INVALID_KEY                  0x35
#define UDS_NRC_TOO_MANY_ATTEMPS             0x36
#define UDS_NRC_TIME_DELAY_NOT_EXPIRED       0x37
#define UDS_NRC_RESPONSE_PENDING             0x78

struct Session_t
{
  uint32_t tx_id=0;
  uint32_t rx_id=0;
  uint8_t  sid=0;
  uint8_t  *Data;
  uint8_t  len=0;
  uint8_t  nrc=0;
};

class UDS
{
	public:
		UDS(IsoTp* isotp);
		void    print_buffer(uint8_t *buffer, uint16_t len);
		uint8_t Session(Session_t* msg);
	private:
		IsoTp* _isotp;
};
#endif

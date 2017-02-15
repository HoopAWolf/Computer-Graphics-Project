#include "LoadATOM.h"
#include <fstream>
#include <string>


/*************************************************************
*	@param:													 *
*	const char*: GETS FILE PATH FOR .ATOM					 *
*	MS*: GET MODEL OBJ TO ANIMATE							 *
*	unsigned: GET STARTING FRAME							 *
*	const string: SETTING OBJ PART NAME						 *
*															 *
*	@return: bool											 *
*	RETURNS TRUE ONCE DONE WITH LOADING OF .ATOM AT FILEPATH *
*	RETURNS FALSE IF CANNOT LOAD .ATOM AT FILEPATH			 *
**************************************************************/
bool LoadAtom(const char *file_path, MS* modelStack, unsigned atThisFrame, const std::string dagNode)
{
	unsigned fps = 0;  //INITIALIZING FPS

	std::ifstream fileStream(file_path, std::ios::binary);  //OPENING OF .ATOM FILE
	if (!fileStream.is_open()) {  //CHECKING IF THERE IS SUCH FILE NAME
		std::cout << "Impossible to open " << file_path << ". Are you in the right directory ?\n";
		return false;
	}

	std::string atfSTR = std::to_string(atThisFrame);  //CONVERTING FRAME STARTING NUMBER TO STRING

	if (atfSTR.size() < 2)  //CHECKING IF THE NUMBER INPUT IS LESS THAN 2 DIGITS
		atfSTR += " ";  //ADD A SPACE IF IT IS LESS THAN 2 DIGITS

	char const *atf = atfSTR.c_str();  //CONVERTING STRING TO CHAR POINTER

	enum TRANSFORM_TYPES
	{
		TX,  //TRANSLATE BY X
		TY,  //TRANSLATE BY Y
		TZ,  //TRANSLATE BY Z
		RX,  //ROTATE BY X AXIS
		RY,  //ROTATE BY Y AXIS
		RZ,  //ROTATE BY Z AXIS
		SX,  //SCALE BY X
		SY,  //SCALE BY Y
		SZ,  //SCALE BY Z
		COUNT //COUNTER FOR TRANSFORM TYPES
	};

	TRANSFORM_TYPES atTransformation = COUNT;  //SETTING TRANSFROM TYPE
	bool isCheckingTransform = false;  //CHECKING FOR TRANSFORMATION
	float transformValues[COUNT] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f };  //STORING OF TX, TY, TZ, RX, RY, RZ, SX, SY, SZ TRANSFORMATION VALUES
	bool isCheckingKey = false;
	bool isCheckingDagNode = false;
	bool atDagNode = false;
	char previousLine[256];

	while (!fileStream.eof()) {  //CHECKING FOR END OF FILE
		char buf[256];  
		fileStream.getline(buf, 256);  //GETTING THE FIRST LINE

		if (strncmp("timeUnit ", buf, 9) == 0)  //COMPARING IF BUF STRING IS SAME AS timeUnit
		{
			char FPSType[10];  //
			sscanf_s((buf + 9), "%s", FPSType, (unsigned)_countof(FPSType));  //READS DATA IN TEXT FROM BUFFER FOR FPS TYPE AND SETTING IT INTO FPSType

			if (FPSType == "ntsc")
				fps = 30;  //SETTING OF FPS FOR REQUIRED ANIMATION SPEED
			//Add more types if needed
		}

		if (strncmp("dagNode {", buf, 9) == 0 && !isCheckingDagNode)  //CHECKING IF BUF STRING IS SAME AS dagNode
		{
			isCheckingDagNode = true;
			continue;
		}

		if (isCheckingDagNode && !atDagNode)
		{
			char dagNodeStr[128];
			sscanf_s((buf + 2), "%s", dagNodeStr, (unsigned)_countof(dagNodeStr));  //READS DATA IN TEXT FROM BUFFER FOR NEXT TEXT AFTER BUF AND SETTING IT TO dagNodeStr
			if (dagNodeStr == dagNode)  //CHECKING IF THE CHECK HAS REACHED THE REQUIRED OBJECT PIECE
				atDagNode = true;
			else
				isCheckingDagNode = false;
		}

		if (atDagNode)  //IF REACHED REQUIRED OBJECT PIECE
		{
			if (strncmp("  anim translate.translateX", buf, 27) == 0)  //COMPARING STRING AND BUF TO SEE IF THEYRE THE SAME
			{
				atTransformation = TX;  //SET TRANSFORMATION TYPE
				isCheckingTransform = true;
				continue;
			}
			else if (strncmp("  anim translate.translateY", buf, 27) == 0)
			{
				atTransformation = TY;
				isCheckingTransform = true;
				continue;
			}
			else if (strncmp("  anim translate.translateZ", buf, 27) == 0)
			{
				atTransformation = TZ;
				isCheckingTransform = true;
				continue;
			}
			else if (strncmp("  anim rotate.rotateX", buf, 21) == 0)
			{
				atTransformation = RX;
				isCheckingTransform = true;
				continue;
			}
			else if (strncmp("  anim rotate.rotateY", buf, 21) == 0)
			{
				atTransformation = RY;
				isCheckingTransform = true;
				continue;
			}
			else if (strncmp("  anim rotate.rotateZ", buf, 21) == 0)
			{
				atTransformation = RZ;
				isCheckingTransform = true;
				continue;
			}
			else if (strncmp("  anim scale.scaleX", buf, 21) == 0)
			{
				atTransformation = SX;
				isCheckingTransform = true;
				continue;
			}
			else if (strncmp("  anim scale.scaleY", buf, 21) == 0)
			{
				atTransformation = SY;
				isCheckingTransform = true;
				continue;
			}
			else if (strncmp("  anim scale.scaleZ", buf, 21) == 0)
			{
				atTransformation = SZ;
				isCheckingTransform = true;
				continue;
			}


			if (isCheckingTransform)
			{
				if (strncmp("    keys {", buf, 10) == 0)  //CHECKING IF BUF IS AT THE KEYS SECTION BY COMPARING STRING
				{
					isCheckingKey = true;
					continue;
				}

				if (isCheckingKey)
				{
					unsigned int frameNum = 0;
					static float defaultValue = 0;
					sscanf_s((buf + 6), "%d", &frameNum);  //SETTING THE CURRENT FRAME NUMBER TO framNum
					if (strncmp("0", buf + 6, 1) == 0)//6 whitespaces, checking the default value
						sscanf_s((buf + 8), "%f", &defaultValue);  //SETTING DEFAULT VALUE TO defaultValue

					if (strncmp(atf, buf + 6, 2) == 0)//6 whitespaces; CHECKING IF buf LOCATION IS AT FRAME
					{
						float value;
						bool numOfBuf = 0;
						if (atThisFrame >= 10)  //IF FRAME INPUT IS MORE THEN OR EQUALS THAN 10
							numOfBuf = 1;
						sscanf_s((buf + 8 + numOfBuf), "%f", &value);  //GETTING VALUE FOR TRANSFORMATION
						transformValues[atTransformation] = (value);  //SETTING VALUE INTO TRANSFORMATION
						isCheckingTransform = false;
						isCheckingKey = false;
						defaultValue = 0.0f;
						continue;
					}

					if (atThisFrame < frameNum)//if frame needed is less than current frame
					{
						float value;
						bool numOfBuf = 0;
						if (frameNum >= 10)  //IF FRAME NUMBER IS MORE THAN OR EQUALS TO 10
							numOfBuf = 1;

						sscanf_s((buf + 8 + numOfBuf), "%f", &value);

						unsigned int prevKeyFrame = 0;
						bool numOfprevKFBuf = 0;
						float prevKeyFrameValue = 0.0f;
						sscanf_s((previousLine + 6), "%d", &prevKeyFrame);  //SETTING PREV KEY FRAME
						if (prevKeyFrame >= 10)
							numOfprevKFBuf = 1;

						sscanf_s((previousLine + 8 + numOfprevKFBuf), "%f", &prevKeyFrameValue);  //SETTING PREV KEY FRAME VALUE
						//PASSING TRANSFORMATION VALUE FROM PREV KEY FRAME INTO transformValues
						transformValues[atTransformation] = prevKeyFrameValue + (float)((float)((float)(atThisFrame - prevKeyFrame) / (float)(frameNum - prevKeyFrame)) * (float)(value - prevKeyFrameValue));

						isCheckingTransform = false;
						isCheckingKey = false;
						defaultValue = 0.0f;
						continue;
					}

					strncpy_s(previousLine, buf, 256);  //COPYING buf INTO previousLine, ALL 256 POKEMO.. OF THEM
				}
			}
		}
	}

	if (!atDagNode)  //IF CANNOT FIND OBJECT PIECE
		return false;

	modelStack->Translate(transformValues[TX], transformValues[TY], transformValues[TZ]);
	modelStack->Rotate(transformValues[RZ], 0, 0, 1);
	modelStack->Rotate(transformValues[RY], 0, 1, 0);
	modelStack->Rotate(transformValues[RX], 1, 0, 0);
	modelStack->Scale(transformValues[SX], transformValues[SY], transformValues[SZ]);

	return true;
}
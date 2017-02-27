#ifndef _ENTITY_NPC_H_
#define _ENTITY_NPC_H_


#include "Entitybase.h"



class EntityNPC abstract : public EntityBase
{
protected:
	enum NPC_STATE
	{
	 WALKING,
	 IDLE,
	 INTERACTION

	};


	NPC_STATE NPC_state_;
	unsigned NPCID_;
	string NPC_name_;
	bool NPCWALKING = false;


public:

    virtual ~EntityNPC(){};

	virtual NPC_STATE getNPCState()
	{
		return NPC_state_;
	}

	virtual string getNPCName()
	{
		return NPC_name_;
	}

	virtual unsigned getNPCID()
	{
		return NPCID_;
	}

	virtual void setState(unsigned state)
	{
		switch (state)
		{
		case 0:
			NPC_state_ = WALKING;
			break;
		case 1:
			NPC_state_ = IDLE;
		case 2:
			NPC_state_ = INTERACTION;
		}
	}

	virtual bool isInteracting()
	{
		return (NPC_state_ == INTERACTION);
	}

	virtual string getInteractionString() = 0;

};































#endif
#ifndef _ENTITY_NPC_H_
#define _ENTITY_NPC_H_


#include "Entitybase.h"



class EntityNPC abstract : public EntityBase
{
protected:
	enum NPC_STATE
	{
	 WALK,
	 IDLE,

	};


	NPC_STATE NPC_state_;
	unsigned NPCID_;
	string NPC_name_;

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

};































#endif
#pragma once


enum class STATE
{
	DEFAULT,
	MOVE,
	ONAIR,
	DEAD,
	END
};

enum class TYPE
{
	PLAYER,
	MONSTER,
	FRAGILE,
	IMMORTAL,
	TRIGGER,
	END
};

enum class DIRECTION
{
	RIGHT,
	TOP,
	LEFT,
	BOTTOM,
	END
};

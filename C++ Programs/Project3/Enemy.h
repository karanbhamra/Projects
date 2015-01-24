#pragma once
class Enemy
{
public:
	Enemy();
	virtual ~Enemy();

	virtual void movePosition() = 0;
	virtual void fireWeapon() = 0;
	virtual void updateStatus() =0;

protected:
	short getXPosition();
	short getYPosition();
	short getWidth();
	short getHeight();
	short getStatus();

	void setXPosition(short);
	void setYPosition(short);
	void setWidth(short);
	void setHeight(short);
	void setStatus(short);

private:
	short x_position;
	short y_position;
	short width;
	short height;
	short status;
};


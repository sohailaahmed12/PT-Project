#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition () 
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 
}

CellPosition::CellPosition (int v, int h)
{ 
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition (int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v) 
{
	if (v >= 0 && v <= 4)
	{
		vCell = v;
		return true;
	}
	///TODO: Implement this function as described in the .h file (don't forget the validation)

	return false; // this line sould be changed with your implementation
}

bool CellPosition::SetHCell(int h) 
{
	if (h >= 0 && h <= 10)
	{
		hCell = h;
		return true;
	}
	///TODO: Implement this function as described in the .h file (don't forget the validation)

	return false; // this line sould be changed with your implementation
}

int CellPosition::VCell() const 
{
	return vCell;
}

int CellPosition::HCell() const 
{
	return hCell;
}

bool CellPosition::IsValidCell() const 
{
	if (vCell < 0 || vCell >= 5)
	{
		return false;
	}
	if (hCell < 0 || hCell >= 11)
	{
		return false;
	}
	///TODO: Implement this function as described in the .h file

	return false; // this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{
	
	if (cellPosition.vCell < 0 || cellPosition.vCell >= 5)
	{
		return -1;
	}
	if (cellPosition.hCell < 0 || cellPosition.hCell >= 10)
	{
		return -1;
	}
	int cellnumber;
		cellnumber = (11 * (5 - cellPosition.vCell - 1) + (cellPosition.hCell + 1));
		return cellnumber;
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	CellPosition position;
	if (cellNum >= 0 && cellNum <= 55)
	{
		position.vCell = 5 - 1 - (cellNum - 1) / 11;
		position.hCell = (cellNum - 1) % 11;
		return position;
	}
	else
	{
		return (-1, -1);
	}
	
}

void CellPosition::AddCellNum(int addedNum, Direction direction)
{
	if (addedNum < 0)
	{
		return;
	}
		int currentcellnum = GetCellNum();  //currentcellnum k2enaha cellnumber
		if (direction == UP)
		{
			currentcellnum = currentcellnum + (addedNum * 11);
		}
		else if (direction == DOWN)
		{
			currentcellnum = currentcellnum - (addedNum * 11);
		}
		else if (direction == LEFT)
		{
			currentcellnum = currentcellnum - addedNum;
		}
		else if (direction == RIGHT)
		{
			currentcellnum = currentcellnum + addedNum;
		}
		else return;
		if (currentcellnum >= 0 && currentcellnum<=55)
		{
			CellPosition currentposition=GetCellPositionFromNum(currentcellnum);
			vCell = currentposition.VCell();
			hCell = currentposition.HCell();
		}
		
		 
	
	
	


	// Note: this function updates the data members (vCell and hCell) of the calling object

}
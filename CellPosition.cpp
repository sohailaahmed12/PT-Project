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
	if (vCell < 0 || vCell >= NumVerticalCells)
	{
		return false;
	}
	if (hCell < 0 || hCell >= NumHorizontalCells)
	{
		return false;
	}
	///TODO: Implement this function as described in the .h file

	return true; // this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{
	
	if (cellPosition.VCell() < 0 || cellPosition.VCell() > NumVerticalCells)
	{
		return -1;
	}
	if (cellPosition.HCell() < 0 || cellPosition.HCell() > NumHorizontalCells)
	{
		return -1;
	}
	int cellnumber;
		cellnumber = (NumHorizontalCells * (NumVerticalCells - cellPosition.VCell() - 1) + (cellPosition.HCell() + 1));
		return cellnumber;
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	CellPosition position;
	if (cellNum >= 1 && cellNum <= 55)
	{
		int vertical = (NumVerticalCells - 1) - ((cellNum - 1) / NumHorizontalCells);
		int horizontal= (cellNum - 1) % NumHorizontalCells;
		position.SetVCell(vertical);
		position.SetHCell(horizontal);
		return position;
	}
	else {
		return position;
	}
}

void CellPosition::AddCellNum(int addedNum, Direction direction)
{
	if (addedNum < 0)
	{
		return;
	}
		int currentcellnum = GetCellNum();  //currentcellnum k2enaha cellnumber
		int currentvcell = VCell();
		int currenthcell = HCell();
		if (direction == UP)
		{
			if (currentvcell- addedNum < 0)
			{
				return;  
			}
			currentcellnum = currentcellnum + (addedNum * NumHorizontalCells);
		}
		else if (direction == DOWN)
		{
			if (currentvcell + addedNum > 4)  
			{
				return;  
			}
			currentcellnum = currentcellnum - (addedNum * NumHorizontalCells);
		}
		else if (direction == LEFT)
		{
			if (currenthcell - addedNum < 0)
			{
				return;  
			}
			currentcellnum = currentcellnum - addedNum;
		}
		else if (direction == RIGHT)
		{
			if (currenthcell + addedNum > 10)
			{
				return;  // Can't move right beyond the last column (column 10)
			}
			currentcellnum = currentcellnum + addedNum;
		}
		else return;

		if (currentcellnum >= 1 && currentcellnum<=55)
		{
			CellPosition currentposition=GetCellPositionFromNum(currentcellnum);
			 SetVCell(currentposition.VCell());
			 SetHCell(currentposition.HCell());
		}
		
	// Note: this function updates the data members (vCell and hCell) of the calling object

}

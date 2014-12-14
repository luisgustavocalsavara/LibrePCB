/*
 * EDA4U - Professional EDA for everyone!
 * Copyright (C) 2013 Urban Bruhin
 * http://eda4u.ubruhin.ch/
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*****************************************************************************************
 *  Includes
 ****************************************************************************************/

#include <QtCore>
#include "cmdschematicnetpointsetnetsignal.h"
#include "../schematicnetpoint.h"

namespace project {

/*****************************************************************************************
 *  Constructors / Destructor
 ****************************************************************************************/

CmdSchematicNetPointSetNetSignal::CmdSchematicNetPointSetNetSignal(SchematicNetPoint& point, NetSignal& netsignal, UndoCommand* parent) throw (Exception) :
    UndoCommand(QCoreApplication::translate("CmdSchematicNetPointSetNetSignal", "Change netpoint netsignal"), parent),
    mNetPoint(point), mNetSignal(netsignal), mOldNetSignal(*point.getNetSignal())
{
}

CmdSchematicNetPointSetNetSignal::~CmdSchematicNetPointSetNetSignal() noexcept
{
}

/*****************************************************************************************
 *  Inherited from UndoCommand
 ****************************************************************************************/

void CmdSchematicNetPointSetNetSignal::redo() throw (Exception)
{
    mNetPoint.setNetSignal(mNetSignal); // throws an exception on error

    try
    {
        UndoCommand::redo(); // throws an exception on error
    }
    catch (Exception &e)
    {
        mNetPoint.setNetSignal(mOldNetSignal);
        throw;
    }
}

void CmdSchematicNetPointSetNetSignal::undo() throw (Exception)
{
    mNetPoint.setNetSignal(mOldNetSignal); // throws an exception on error

    try
    {
        UndoCommand::undo();
    }
    catch (Exception& e)
    {
        mNetPoint.setNetSignal(mNetSignal);
        throw;
    }
}

/*****************************************************************************************
 *  End of File
 ****************************************************************************************/

} // namespace project

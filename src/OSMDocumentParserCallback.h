/***************************************************************************
 *   Copyright (C) 2008 by Daniel Wendt                                    *
 *   gentoo.murray@gmail.com                                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef SRC_OSMDOCUMENTPARSERCALLBACK_H_
#define SRC_OSMDOCUMENTPARSERCALLBACK_H_

#include <string.h>
#include "./XMLParser.h"

namespace osm2pgr {

class OSMDocument;
class Way;
class Relation;

/**
    Parser callback for OSMDocument files
*/
class OSMDocumentParserCallback :
  public xml::XMLParserCallback {
    //! reference to a OSMDocument object
    OSMDocument& m_rDocument;
    //! current way, which will be parsed
    Way* m_pActWay;
    Relation* m_pActRelation;

    virtual void StartElement(const char *name, const char** atts);

    virtual void EndElement(const char* name);

#if 0
    virtual void SetContent(const char* ch, int len)=0;

    virtual void ProcessingInstruction(const char* target, const char* data)=0;

    virtual void CDataBlockInternal(const char *value, int len)=0;
#endif
 public:
    /**
     *    Constructor
     */
    OSMDocumentParserCallback(OSMDocument& doc)
    :
        m_rDocument(doc),
        m_pActWay(0),
        m_pActRelation(0)

    {
    }
};  // class OSMDocumentParserCallback

}  // end namespace osm2pgr

#endif  // SRC_OSMDOCUMENTPARSERCALLBACK_H_

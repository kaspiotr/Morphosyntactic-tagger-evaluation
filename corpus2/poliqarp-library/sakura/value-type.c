/*
 * This file is part of the Poliqarp suite.
 * 
 * Copyright (C) 2004-2009 by Instytut Podstaw Informatyki Polskiej
 * Akademii Nauk (IPI PAN; Institute of Computer Science, Polish
 * Academy of Sciences; cf. www.ipipan.waw.pl).  All rights reserved.
 * 
 * This file may be distributed and/or modified under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation and appearing in the file gpl.txt included in the packaging
 * of this file.  (See http://www.gnu.org/licenses/translations.html for
 * unofficial translations.)
 * 
 * A commercial license is available from IPI PAN (contact
 * Michal.Ciesiolka@ipipan.waw.pl or ipi@ipipan.waw.pl for more
 * information).  Licensees holding a valid commercial license from IPI
 * PAN may use this file in accordance with that license.
 * 
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING
 * THE WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE.
 */

#include <errno.h>

#include <sakura/value-type.h>

struct poliqarp_value *poliqarp_value_create_type(
   const struct poliqarp_corpus *corpus, const struct poliqarp_regexp *pattern)
{
   struct poliqarp_value *this = NULL;

   if (!corpus->syntax.syntax) {
      errno = EINVAL;
      return NULL;
   }
   this = poliqarp_value_pattern_create(&corpus->syntax.dict_types, pattern);
   this->domain = POLIQARP_DOMAIN_TYPE;
   return this;
}

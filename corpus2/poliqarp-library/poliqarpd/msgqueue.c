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

#include <stdlib.h>

#include "msgqueue.h"

void msgqueue_init(struct msgqueue *queue)
{
   queue->first = queue->last = NULL;
}

void msgqueue_append(struct msgqueue *queue, string_t str)
{
   struct msgqueue_elem *el = malloc(sizeof(*el));
   el->msg = str;
   el->next = NULL;
   if (queue->first) {
      queue->last->next = el;
      queue->last = el;
   } else {
      queue->first = queue->last = el;
   }
}

string_t msgqueue_get(struct msgqueue *queue)
{
   if (queue->first) {
      struct msgqueue_elem *el = queue->first;
      string_t msg = el->msg;
      
      queue->first = el->next;
      if (el->next == NULL)
         queue->last = NULL;
      free(el);
      return msg;
   } else
      return NULL;
}

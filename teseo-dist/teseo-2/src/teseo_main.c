/* Teseo-2 Plug-in
 * Copyright (C) 2005  Stefano Pintore, Matteo Quintiliani (the "Authors").
 * All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE Authors BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Except as contained in this notice, the name of the Authors of the
 * Software shall not be used in advertising or otherwise to promote the
 * sale, use or other dealings in this Software without prior written
 * authorization from the Authors.
 */

#include <libgimp/gimp.h>
#include "teseo_main.h"
#include "teseo_path.h"

/*!
 * ALGORITHM function pointer to real algorithm function
 */
static int  ( * ALGORITHM   )  ( const void *  is,  void * os );
/*!
 * INIT_ALG function pointer to real init_alg function to be call before ALGORITHM,
 \param constants pointer to initialise the algorithm
 */
static void ( * INIT_ALG    )  ( void * constants );
/*!
 * GETINPUT function pointer to real getinput function
 *
 */
static int  ( * GETINPUT    )  ( void * is,  const void * previous_os, gint32 drawable_ID );
/*!
 * TERMINATE function pointer to real terminate function
 */
static int  ( * TERMINATE   )  ( void * os, void * is, gint32 drawable_ID );
/*!
 * ACCUMULATE function pointer to real accumulate function
 */
static int  ( * ACCUMULATE  )  ( double ** strokes, long * num_strokes, void * os );
/*!
 * STARTING_OS function pointer to real starting_os function
 */
static int  ( * STARTING_OS )  ( void * os, gint32 drawable_ID );

/*!
 * RELEASE function pointer to real release function
 */
static void ( * RELEASE     )  ( void * is, void *os);
/*!
 * NEW_IS function pointer to real new_is function
 */
static int  ( * NEW_IS      )  ( void * is, gint32 drawable_ID);

void teseo_main_init(
		     int  (* alg)         ( const void * is, void * os ),
		     void (* init_alg)    ( void * constants ),
		     void  * sth,
		     int  (* getinput)    ( void * is,  const void * previous_os, gint32 drawable_ID ),
		     int  (* terminate)   ( void * os , void * is, gint32 drawable_ID ),
		     int  (* accumulate)  ( double ** strokes, long * num_strokes, void * os ),
		     int  (* starting_os) ( void ** os, gint32 drawable_ID ),
		     int  (* new_is)      ( void ** is, gint32 drawable_ID ),
		     void  (* release)     ( void ** is, void ** os )
		     )
{
  ALGORITHM = alg;
  INIT_ALG  = init_alg;
  INIT_ALG(sth);

  GETINPUT    = getinput;
  TERMINATE   = terminate;
  ACCUMULATE  = accumulate;
  STARTING_OS = starting_os;
  NEW_IS      = new_is;
  RELEASE     = release;
}

void teseo_main_loop(int iter, gint32 drawable_ID ){
  //after a teseo_main_init() call you can use your ALGORITHM here
  int i;
  void * os=NULL;
  void * is=NULL;
  gdouble * strokes=NULL;
  gulong num_strokes=0;
  wm_os * myos;

  //initialize os as an ipothetique last running

  if (STARTING_OS(&os,drawable_ID)) {
    NEW_IS(&is,drawable_ID);
    if ( ! TERMINATE(os, is, drawable_ID ) ) {
      for (i=0; i<iter; i++){
       //get is from drawable and os
       if ( ! GETINPUT(is, os, drawable_ID) ) break;
       //get os running the algorithm
       if ( ! ALGORITHM( is, os ) ) break;
       ACCUMULATE(&strokes, &num_strokes, os);
       //testing an escape condition on output os
       if ( TERMINATE(os, is, drawable_ID ) ) break;
      }
    }
    //TODO generalise?
    teseo_cat_path_strokes( gimp_drawable_get_image(drawable_ID), num_strokes, strokes);
    //strokes_to_open_path(gimp_drawable_get_image(drawable_ID), num_strokes, strokes, "Path");
    g_free(strokes);

    RELEASE(&is,&os);
  }
}



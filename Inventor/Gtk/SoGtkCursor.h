/**************************************************************************\
 *
 *  This file is part of the Coin family of 3D visualization libraries.
 *  Copyright (C) 1998-2003 by Systems in Motion.  All rights reserved.
 *
 *  This library is free software; you can redistribute it and / or
 *  modify it under the terms of the GNU General Public License
 *  version 2 as published by the Free Software Foundation.  See the
 *  file LICENSE.GPL at the root directory of this source distribution
 *  for more details.
 *
 *  If you desire to use this library in software that is incompatible
 *  with the GNU GPL, and / or you would like to take advantage of the
 *  additional benefits with regard to our support services, please
 *  contact Systems in Motion about acquiring a Coin Professional
 *  Edition License.  See <URL:http://www.coin3d.org> for more
 *  information.
 *
 *  Systems in Motion, Abels gate 5, Teknobyen, 7030 Trondheim, NORWAY
 *  <URL:http://www.sim.no>, <mailto:support@sim.no>
 *
\**************************************************************************/

#ifndef SOGTK_CURSOR_H
#define SOGTK_CURSOR_H

#include <Inventor/SbLinear.h>
#include <Inventor/Gtk/SoGtkBasic.h>

#ifdef __PIVY__
%rename(SoGtkCursor_sha) SoGtkCursor::SoGtkCursor(const Shape shape);
%rename(SoGtkCursor_cc) SoGtkCursor::SoGtkCursor(const SoGtkCursor::CustomCursor * cc);

%feature("shadow") SoGtkCursor::SoGtkCursor %{
def __init__(self,*args):
   if len(args) == 1:
      if isinstance(args[0], CustomCursor):
         self.this = apply(_pivy.new_SoGtkCursor_cc,args)
         self.thisown = 1
         return
      else:
         self.this = apply(_pivy.new_SoGtkCursor_sha,args)
         self.thisown = 1
         return
   self.this = apply(_pivy.new_SoGtkCursor,args)
   self.thisown = 1
%}
#endif

class SOGTK_DLL_API SoGtkCursor {
public:
#ifdef __PIVY__
  typedef struct CustomCursor CustomCursor;
#endif
  struct CustomCursor {
    SbVec2s dim;
    SbVec2s hotspot;
    unsigned char * bitmap;
    unsigned char * mask;
  };


  // FIXME: add more default shapes. 20011119 pederb.
  enum Shape {
    CUSTOM_BITMAP = -1,
    DEFAULT = 0,
    BUSY,
    CROSSHAIR,
    UPARROW
  };
  
  SoGtkCursor(void);
  SoGtkCursor(const Shape shape);
#ifdef __PIVY__
  SoGtkCursor(const SoGtkCursor::CustomCursor * cc);
#else
  SoGtkCursor(const CustomCursor * cc);
#endif
  SoGtkCursor(const SoGtkCursor & cursor);
  ~SoGtkCursor();

  SoGtkCursor & operator=(const SoGtkCursor & c);

  Shape getShape(void) const;
  void setShape(const Shape shape);

#ifdef __PIVY__
  const SoGtkCursor::CustomCursor & getCustomCursor(void) const;
#else
  const CustomCursor & getCustomCursor(void) const;
#endif

  static const SoGtkCursor & getZoomCursor(void);
  static const SoGtkCursor & getPanCursor(void);
  static const SoGtkCursor & getRotateCursor(void);
  static const SoGtkCursor & getBlankCursor(void);
  
private:
  void commonConstructor(const Shape shape, const CustomCursor * cc);

  Shape shape;
  CustomCursor * cc;
};

#endif // ! SOGTK_CURSOR_H

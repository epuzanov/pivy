/**************************************************************************\
 *
 *  This file is part of the Coin 3D visualization library.
 *  Copyright (C) 1998-2002 by Systems in Motion. All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public License
 *  version 2.1 as published by the Free Software Foundation. See the
 *  file LICENSE.LGPL at the root directory of the distribution for
 *  more details.
 *
 *  If you want to use Coin for applications not compatible with the
 *  LGPL, please contact SIM to acquire a Professional Edition license.
 *
 *  Systems in Motion, Prof Brochs gate 6, 7030 Trondheim, NORWAY
 *  http://www.sim.no support@sim.no Voice: +47 22114160 Fax: +47 22207097
 *
\**************************************************************************/

#ifndef COIN_SOONESHOTSENSOR_H
#define COIN_SOONESHOTSENSOR_H

#include <Inventor/sensors/SoDelayQueueSensor.h>

#ifdef __PIVY__
%rename(SoOneShotSensor_scb_v) SoOneShotSensor::SoOneShotSensor(SoSensorCB * func, void * data);

%feature("shadow") SoOneShotSensor::SoOneShotSensor %{
def __init__(self,*args):
   if len(args) == 2:
      args = (args[0], (args[0], args[1]))
      self.this = apply(pivyc.new_SoOneShotSensor_scb_v,args)
      self.thisown = 1
      return
   self.this = apply(pivyc.new_SoOneShotSensor,args)
   self.thisown = 1
%}
#endif

class COIN_DLL_API SoOneShotSensor : public SoDelayQueueSensor {
  typedef SoDelayQueueSensor inherited;

public:
  SoOneShotSensor(void);
  SoOneShotSensor(SoSensorCB * func, void * data);
  virtual ~SoOneShotSensor(void);
};

#endif // !COIN_SOONESHOTSENSOR_H

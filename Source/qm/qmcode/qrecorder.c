/*****************************************************************************
* Model: bwgpsrecorder.qm
* File:  qmcode/qrecorder.c
*
* This code has been generated by QM tool (see state-machine.com/qm).
* DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
*
* This program is open source software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published
* by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
* or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
* for more details.
*****************************************************************************/
/* @(/3/14) ................................................................*/
#include "qp_port.h"
#include "qevents.h"
#include "bsp.h"
#include "type.h"
#include "protocol.h"
#include "utility.h"
#include "error.h"


Q_DEFINE_THIS_MODULE("qrecorder.c")



/* Active object class -----------------------------------------------------*/
/* @(/1/13) ................................................................*/
typedef struct QRecorderTag {
/* protected: */
    QActive super;
} QRecorder;

/* protected: */
static QState QRecorder_initial(QRecorder * const me, QEvt const * const e);
static QState QRecorder_state1(QRecorder * const me, QEvt const * const e);



/* Local objects -----------------------------------------------------------*/
static QRecorder l_Recorder; /* the single instance of the Table active object */

/* Global-scope objects ----------------------------------------------------*/
QActive * const AO_Recorder = &l_Recorder.super; /* "opaque" AO pointer */

/*..........................................................................*/
/* @(/1/35) ................................................................*/
void QRecorder_ctor(void) {
    QRecorder *me = &l_Recorder;
    QActive_ctor(&me->super, Q_STATE_CAST(&QRecorder_initial));
}
/* @(/1/13) ................................................................*/
/* @(/1/13/0) ..............................................................*/
/* @(/1/13/0/0) */
static QState QRecorder_initial(QRecorder * const me, QEvt const * const e) {
    return Q_TRAN(&QRecorder_state1);
}
/* @(/1/13/0/1) ............................................................*/
static QState QRecorder_state1(QRecorder * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        default: {
            status_ = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status_;
}


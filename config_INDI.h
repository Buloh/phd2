/*
 *  config_INDI.cpp
 *  PHD Guiding
 *
 *  Created by Craig Stark
 *  Copyright (c) 2006, 2007, 2008, 2009 Craig Stark.
 *  All rights reserved.
 *
 *  Redraw for libindi/baseclient by Patrick Chevalley
 *  Copyright (c) 2014 Patrick Chevalley
 *  All rights reserved.
 *
 *  This source code is distributed under the following "BSD" license
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *    Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *    Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *    Neither the name of Craig Stark, Stark Labs nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 */


#ifndef _CONFIG_INDI_H_
#define _CONFIG_INDI_H_

#include <libindi/baseclient.h>
#include <libindi/basedevice.h>
#include <libindi/indiproperty.h>
#ifndef INDI_PRE_1_1_0
   #include <libindi/indibasetypes.h>
#endif

#include "indi_gui.h"

enum {
    TYPE_CAMERA,
    TYPE_MOUNT,
    TYPE_AO,
};

class INDIConfig : public wxDialog , public INDI::BaseClient {
public:
    INDIConfig(wxWindow *parent, int devtype);
    ~INDIConfig();
    long     INDIport;
    wxString INDIhost;
    wxString INDIDevName;
    long     INDIDevCCD;
    bool     INDIForceVideo;
    wxString INDIDevPort;
    void Connect();
    void Disconnect();
    void SetSettings();
    void SaveSettings();

private:
    void OnConnectButton(wxCommandEvent& evt);
    void OnIndiGui(wxCommandEvent& evt);
    IndiGui  *gui ;
    wxTextCtrl *host;
    wxTextCtrl *port;
    wxStaticText *connect_status;
    wxStaticText *devlabel;
    wxComboBox *dev;
    wxComboBox *ccd;
    wxTextCtrl *devport;
    wxCheckBox *forcevideo;
    int dev_type;
    DECLARE_EVENT_TABLE()

protected:
    void newDevice(INDI::BaseDevice *dp) override;
#ifndef INDI_PRE_1_0_0
    void removeDevice(INDI::BaseDevice *dp) override {};
#endif
    void newProperty(INDI::Property *property) override {}
    void removeProperty(INDI::Property *property) override {}
    void newBLOB(IBLOB *bp) override {}
    void newSwitch(ISwitchVectorProperty *svp) override {}
    void newNumber(INumberVectorProperty *nvp) override {}
    void newMessage(INDI::BaseDevice *dp, int messageID) override {}
    void newText(ITextVectorProperty *tvp) override {}
    void newLight(ILightVectorProperty *lvp) override {}
    void serverConnected() override {}
    void serverDisconnected(int exit_code) override {}

};

#endif

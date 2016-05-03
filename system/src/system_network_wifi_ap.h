/**
 ******************************************************************************
  Copyright (c) 2016 Particle Industries, Inc.  All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation, either
  version 3 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************
 */

#pragma once

#include "spark_wiring_platform.h"

#if Wiring_WiFi_AP

#include "system_network_internal.h"
#include "system_network_wifi.h"
#include "wlan_ap_hal.h"

extern WiFiNetworkInterface wifi;

// todo - rename NetworkInterface to NetworkClientInterface and make a simpler base class that doesn't have the client methods.
class WiFiAPNetworkInterface : public NetworkInterface
{
public:
    static const network_interface_t INTERFACE_ID = 1;

    virtual network_interface_t network_interface() {
    		return INTERFACE_ID;
    }

    /**
     * Initialize this instance.
     */
    virtual void setup() override
    {
    }

    /**
     * Delegates to the main WiFi network interface.
     */
    virtual void on(bool update_led) override
    {
    		wifi.on(update_led);
    }

    /**
     * Disconnects this AP mode interface and shutsdown the main wifi module.
     */
    virtual void off(bool disconnect_cloud=false) override
    {
    		wifi.off(disconnect_cloud);
    }

    /**
     * Brings up the AP mode interface.
     */
    virtual void connect(bool listen_enabled=true) override
    {
    }

    /**
     * Determines if the AP mode interface is presently being
     * brought up.
     */
    virtual bool connecting() override
    {
    		return false;
    }

    /**
     * Determines if the AP mode interface was successfully
     * brought up.
     */
    virtual bool connected() override
    {
    		return false;
    }

    /**
     * Attempts to cancel bringing up the AP mode interface.
     *
     */
    virtual void connect_cancel(bool cancel) override
    {

    }

    /**
     * Force a manual disconnect. Brings down the AP interface.
     */
    virtual void disconnect() override
    {

    }

    /**
     * @return {@code true} if this connection was manually taken down
     * by a call to disconnect/off.
     */
    virtual bool manual_disconnect() override
    {
    		return false;
    }

    /**
     * Begin WPA enrollment.
     */
    virtual void listen(bool stop=false) override
    {
    }

    virtual void listen_loop() override
    {

    }
    virtual bool listening() override
    {
    		return false;
    }

    /**
     * Perform the 10sec press command, e.g. clear credentials.
     */
    virtual void listen_command() override
    {
    }

    virtual bool ready()  override
    {
    		return false;
    }

    virtual bool clear_credentials() override
    {
    		return !wlan_ap_set_credentials(nullptr, nullptr);
    }

    /**
     * Determines if the credentials have been changed from the defaults.
     */
    virtual bool has_credentials() override
    {
    		return wlan_ap_has_credentials(nullptr)==0;
    }

    virtual int set_credentials(NetworkCredentials* creds) override
    {
		return creds ? wlan_ap_set_credentials(creds, nullptr) : -1;
    }

    virtual void config_clear() override
    {
    }

    virtual void update_config(bool force=false) override
    {
    }

    virtual void* config() override
    {
    		return nullptr;
    }


};



#endif

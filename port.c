/*
  stm32flash - Open Source ST STM32 flash program for *nix
  Copyright (C) 2014 Antonio Borneo <borneo.antonio@gmail.com>

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include <stdint.h>
#include <stdio.h>

#include "serial.h"
#include "port.h"

extern struct port_interface port_serial;
extern struct port_interface port_i2c;
extern struct port_interface port_network;

#if 0
/* used when probing for different available interfaces. here, we focus on udp */
static struct port_interface *ports[] = {
	&port_serial,
	&port_i2c,
	&port_network,
	NULL,
};
#endif

port_err_t port_init(int option, char const * const dev_name, struct port_options *ops, struct port_interface **outport) {
    static struct port_interface *port = NULL;
    int ret = PORT_ERR_UNKNOWN;
    switch (option) {
        case INTERFACE_UDP:
            port = &port_network;
            ret = port->open(port, ops);
            *outport = port;
            break;

        case INTERFACE_SERIAL:
            port = &port_serial;
            ops->device = dev_name;
            ret = port->open(port, ops);
            *outport = port;
            break;
    }
    return ret;
}

port_err_t port_open(struct port_options *ops, struct port_interface **outport) {
    static struct port_interface *port = &port_network;
    int ret = port->open(port, ops);
    *outport = port;
    return ret;
}

#if 0

port_err_t port_open(struct port_options *ops, struct port_interface **outport)
{
	int ret;
	static struct port_interface **port;

	for (port = ports; *port; port++) {
		ret = (*port)->open(*port, ops);
		if (ret == PORT_ERR_NODEV)
			continue;
		if (ret == PORT_ERR_OK)
			break;
		if (ret == PORT_ERR_BAUD)
			fprintf(stderr, "Unsupported baud rate\n");
		fprintf(stderr, "Error probing interface \"%s\"\n",
			(*port)->name);
	}
	if (*port == NULL) {
		fprintf(stderr, "Cannot handle device \"%s\"\n",
			ops->device);
		return PORT_ERR_UNKNOWN;
	}

	*outport = *port;
	return PORT_ERR_OK;
}

#endif


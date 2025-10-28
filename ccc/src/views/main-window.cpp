// SPDX-License-Identifier: MIT
//
// Copyright 2025 Michael Rodriguez
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the “Software”), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <QMenuBar>
#include "main-window.h"

static struct cmd_menu_entry_data {
	const QString name;
	const QString desc;
	const enum clrc663_cmd cmd;
} const menu_cmd_entries[CLRC663_CMD_NUM_TOTAL] = {
	// clang-format off

	[CLRC663_CMD_IDLE] = {
		.name	= "Idle",
		.desc	= "no action, cancels current command execution",
		.cmd	= CLRC663_CMD_IDLE
	},

	[CLRC663_CMD_LPCD] = {
		.name	= "LPCD",
		.desc	= "low-power card detection",
		.cmd	= CLRC663_CMD_LPCD
	},

	[CLRC663_CMD_LOAD_KEY] = {
		.name	= "LoadKey",
		.desc	= "reads a MIFARE Classic key (size of 6 bytes) from "
			  "FIFO buffer ant puts it into Key buffer",
		.cmd	= CLRC663_CMD_LOAD_KEY
	},

	[CLRC663_CMD_MF_AUTHENT] = {
		.name	= "MFAuthent",
		.desc	= "performs the MIFARE Classic authentication",
		.cmd	= CLRC663_CMD_MF_AUTHENT
	},

	[CLRC663_CMD_ACK_REQ] = {
		.name	= "AckReq",
		.desc	= "performs a query, an Ack and a Req-Rn for ISO/IEC "
			  "18000-3 mode 3/ EPC Class-1 HF",
		.cmd	= CLRC663_CMD_ACK_REQ
	},

	[CLRC663_CMD_RECEIVE] = {
		.name	= "Receive",
		.desc	= "activates the receive circuit",
		.cmd	= CLRC663_CMD_RECEIVE
	},

	[CLRC663_CMD_TRANSMIT] = {
		.name	= "Transmit",
		.desc	= "transmits data from the FIFO buffer",
		.cmd	= CLRC663_CMD_TRANSMIT
	},

	[CLRC663_CMD_TRANSCEIVE] = {
		.name	= "Transceive",
		.desc	= "transmits data from the FIFO buffer and "
			  "automatically activates the receiver after "
			  "transmission finished",
		.cmd	= CLRC663_CMD_TRANSCEIVE
	},

	[CLRC663_CMD_WRITE_E2] = {
		.name	= "WriteE2",
		.desc	= "gets one byte from FIFO buffer and writes it to the "
			  "internal EEPROM",
		.cmd	= CLRC663_CMD_WRITE_E2
	},

	[CLRC663_CMD_WRITE_E2_PAGE] = {
		.name	= "WriteE2Page",
		.desc	= "gets up to 64 bytes (one EEPROM page) from the FIFO "
			  "buffer and writes it to the EEPROM",
		.cmd	= CLRC663_CMD_WRITE_E2_PAGE
	},

	[CLRC663_CMD_READ_E2] = {
		.name	= "ReadE2",
		.desc	= "reads data from the EEPROM and copies it into the "
			  "FIFO buffer",
		.cmd	= CLRC663_CMD_READ_E2
	},

	[CLRC663_CMD_LOAD_REG] = {
		.name	= "LoadReg",
		.desc	= "reads data from the internal EEPROM and initializes"
			  " the CLRC663 registers. EEPROM address needs to be "
			  "within EEPROM sector 2",
		.cmd	= CLRC663_CMD_LOAD_REG
	},

	[CLRC663_CMD_LOAD_PROTOCOL] = {
		.name	= "LoadProtocol",
		.desc	= "reads data from the internal EEPROM and initializes "
			  "the CLRC663 registers needed for a Protocol change",
		.cmd	= CLRC663_CMD_LOAD_PROTOCOL
	},

	[CLRC663_CMD_LOAD_KEY_E2] = {
		.name	= "LoadKeyE2",
		.desc	= "copies a key from the EEPROM into the key buffer",
		.cmd	= CLRC663_CMD_LOAD_KEY_E2
	},

	[CLRC663_CMD_STORE_KEY_E2] = {
		.name	= "StoreKeyE2",
		.desc	= "stores a MIFARE Classic key (size of 6 bytes) into "
			  "the EEPROM",
		.cmd	= CLRC663_CMD_STORE_KEY_E2
	},

	[CLRC663_CMD_READ_RNR] = {
		.name	= "ReadRNR",
		.desc	= "Copies bytes from the Random Number generator into "
			  "the FIFO until the FiFo is full",
		.cmd	= CLRC663_CMD_READ_RNR
	},

	[CLRC663_CMD_SOFT_RESET] = {
		.name	= "SoftReset",
		.desc	= "resets the CLRC663",
		.cmd	= CLRC663_CMD_SOFT_RESET
	}

	// clang-format on
};

main_window_view::main_window_view() noexcept
{
	setWindowTitle("OM26630FDK Playground - Command & Control Center");
	resize(1280, 720);

	statusBar();
	menu_bar_populate_cmds();
}

void main_window_view::menu_bar_populate_cmds() noexcept
{
	menu_cmd = menuBar()->addMenu(tr("&Command"));

	for (const struct cmd_menu_entry_data &entry : menu_cmd_entries) {
		QAction *const item = menu_cmd->addAction(entry.name);
		item->setStatusTip(entry.desc);
		menu_cmd->addAction(item);

		connect(item, &QAction::triggered, [this, &entry] {
			// clang-format off
			emit execute_cmd(entry.cmd);
			// clang-format on
		});
	}
}
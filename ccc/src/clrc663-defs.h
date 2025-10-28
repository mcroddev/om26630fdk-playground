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

#pragma once

enum clrc663_cmd {
	CLRC663_CMD_IDLE,
	CLRC663_CMD_LPCD,
	CLRC663_CMD_LOAD_KEY,
	CLRC663_CMD_MF_AUTHENT,
	CLRC663_CMD_ACK_REQ,
	CLRC663_CMD_RECEIVE,
	CLRC663_CMD_TRANSMIT,
	CLRC663_CMD_TRANSCEIVE,
	CLRC663_CMD_WRITE_E2,
	CLRC663_CMD_WRITE_E2_PAGE,
	CLRC663_CMD_READ_E2,
	CLRC663_CMD_LOAD_REG,
	CLRC663_CMD_LOAD_PROTOCOL,
	CLRC663_CMD_LOAD_KEY_E2,
	CLRC663_CMD_STORE_KEY_E2,
	CLRC663_CMD_READ_RNR,
	CLRC663_CMD_SOFT_RESET,
	CLRC663_CMD_NUM_TOTAL
};
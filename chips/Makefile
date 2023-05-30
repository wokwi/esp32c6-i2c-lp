# SPDX-FileCopyrightText: © 2023 Uri Shaked <uri@wokwi.com>
# SPDX-License-Identifier: MIT

SOURCES = bh1750.chip.c
TARGET  = bh1750.chip.wasm

$(TARGET): $(SOURCES) wokwi-api.h
		docker run -v $(shell pwd):/src wokwi/builder-clang-wasm \
	  	clang --target=wasm32-unknown-wasi --sysroot /opt/wasi-libc -nostartfiles -Wl,--import-memory -Wl,--export-table -Wl,--no-entry -Werror -o $(TARGET) $(SOURCES)

.PHONY: clean
clean:
		rm -f $(TARGET)

export PATH := $(HOME)/.platformio/penv/bin:$(PATH)

ifdef INSIDE_EMACS
	FILTER = 2>&1 | sed 's/src\///'
else
	FILTER = 
endif

upload:
	(platformio run --target upload) $(FILTER)

build:
	(platformio run) $(FILTER)

clean:
	platformio run --target clean

monitor:
	platformio device monitor

init:
	platformio project init --ide emacs --board ATtiny202 \
		--project-option "framework=arduino" \
		--project-option "board_build.f_cpu=16000000L" \
		--project-option "upload_protocol=serialupdi" \
		--project-option "upload_speed=57600" \
		--project-option "upload_port=/dev/ttyUSB0"



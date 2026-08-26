export PATH := $(HOME)/.platformio/penv/bin:$(PATH)

ifdef INSIDE_EMACS
	FILTER = 2>&1 | sed 's/src\///'
else
	FILTER = 
endif

# --- ЦІЛІ ДЛЯ ОСНОВНОГО ПРОЄКТУ (P-BrakeIndicator) ---
upload:
	(platformio run --target upload -e brake_indicator) $(FILTER)

build:
	(platformio run -e brake_indicator) $(FILTER)

# --- ЦІЛІ ДЛЯ ТЕСТУВАННЯ ЗАЛІЗА (Blink) ---
upload-test:
	(platformio run --target upload -e blink_test) $(FILTER)

build-test:
	(platformio run -e blink_test) $(FILTER)

clean:
	platformio run --target clean

monitor:
	platformio device monitor

init:
	# 1. Base project init
	platformio project init --ide emacs --board ATtiny202 \
		--project-option "framework=arduino" \
		--project-option "board_build.f_cpu=16000000L" \
		--project-option "upload_protocol=serialupdi" \
		--project-option "upload_speed=57600" \
# 		--project-option "upload_port=/dev/ttyUSB0"
# Auto-detected by default; uncomment the previous line if you need a manual port

	# 2. Add custom profiles to platformio.ini
	@echo "" >> platformio.ini
	@echo "; Automatic detection or manual port selection (uncomment if needed)" >> platformio.ini
	@echo "; upload_port = /dev/ttyUSB0" >> platformio.ini
	@echo "" >> platformio.ini
	@echo "[env:brake_indicator]" >> platformio.ini
	@echo "extends = env:ATtiny202" >> platformio.ini
	@echo "src_filter = +<brake_indicator.c> -<blink_test.c>" >> platformio.ini
	@echo "" >> platformio.ini
	@echo "[env:blink_test]" >> platformio.ini
	@echo "extends = env:ATtiny202" >> platformio.ini
	@echo "src_filter = +<blink_test.c> -<brake_indicator.c>" >> platformio.ini

# netebook_watchdog

- nano /etc/udev/rules.d/99-arduino-watchdog.rules
- udevadm control --reload-rules
- nano /usr/local/bin/keep_alive.sh
- chmod +x /usr/local/bin/keep_alive.sh
- systemctl daemon-reload
- systemctl enable keep_alive.service
- systemctl restart keep_alive.service
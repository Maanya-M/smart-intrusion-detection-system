# Digital Clock - World Time Zones

A Python application that displays the current time across multiple time zones with both command-line and graphical user interfaces.

## Features

### Core Features
- ✅ Display current time in multiple time zones simultaneously
- ✅ Support for 24-hour and 12-hour time formats
- ✅ Shows date, day of week, and UTC offset for each timezone
- ✅ Add/remove custom time zones dynamically
- ✅ Detailed timezone information (DST status, UTC offset, etc.)
- ✅ List all available timezones

### GUI Features
- 🖥️ Interactive graphical interface with tkinter
- 🎨 Dark theme with color-coded displays
- 🔄 Real-time clock updates every second
- ➕ Add new timezones through the interface
- ✕ Remove timezones with a single click
- 📜 Scrollable timezone list
- 📊 Current UTC time display at the top

## Installation

### Requirements
```bash
pip install pytz
```

For GUI support, tkinter is usually included with Python. If not:
```bash
# Ubuntu/Debian
sudo apt-get install python3-tk

# macOS (with Homebrew)
brew install python-tk

# Windows
# Included with Python installation
```

## Usage

### Command-Line Interface

```python
from digital_clock import DigitalClock

# Create a clock with default timezones
clock = DigitalClock()

# Display 24-hour format
print(clock.display_clock())

# Display 12-hour format
print(clock.display_12hour_format())

# Get timezone info
info = clock.get_timezone_info('US/Pacific')
print(info)

# Add custom timezone
clock.add_timezone('Asia/Kolkata')

# Remove timezone
clock.remove_timezone('Europe/London')

# Get all available timezones
timezones = clock.list_available_timezones()
print(len(timezones), "timezones available")
```

#### Run the CLI Demo
```bash
python digital_clock.py
```

### Graphical User Interface

```python
from digital_clock_gui import DigitalClockGUI
import tkinter as tk

root = tk.Tk()
app = DigitalClockGUI(root)
root.mainloop()
```

#### Run the GUI Application
```bash
python digital_clock_gui.py
```

## Default Timezones

The application comes with these default timezones:
- **US Timezones**: Eastern, Central, Mountain, Pacific
- **Europe**: London, Paris
- **Asia**: Tokyo, Shanghai
- **Oceania**: Sydney
- **Reference**: UTC

## API Reference

### DigitalClock Class

#### Methods

**`__init__(time_zones=None)`**
- Initialize clock with optional custom timezone list

**`get_time_in_zone(timezone: str) -> datetime`**
- Get current time in a specific timezone

**`display_clock() -> str`**
- Display times in 24-hour format

**`display_12hour_format() -> str`**
- Display times in 12-hour format (AM/PM)

**`get_timezone_info(timezone: str) -> Dict`**
- Get detailed information about a timezone
- Returns: time, date, day, UTC offset, DST status

**`add_timezone(timezone: str) -> bool`**
- Add a new timezone to the display

**`remove_timezone(timezone: str) -> bool`**
- Remove a timezone from the display

**`list_available_timezones() -> List[str]`**
- Get all available timezone strings

## Example Output

### CLI Display (24-hour format)
```
============================================================
DIGITAL CLOCK - WORLD TIME ZONES
============================================================
Last Updated: 2026-05-14 15:30:45
============================================================

US/Eastern               | 11:30:45 | 2026-05-14 | UTC-04:00
US/Central               | 10:30:45 | 2026-05-14 | UTC-05:00
US/Mountain              | 09:30:45 | 2026-05-14 | UTC-06:00
US/Pacific               | 08:30:45 | 2026-05-14 | UTC-07:00
Europe/London            | 16:30:45 | 2026-05-14 | UTC+01:00
Europe/Paris             | 17:30:45 | 2026-05-14 | UTC+02:00
Asia/Tokyo               | 23:30:45 | 2026-05-15 | UTC+09:00
Asia/Shanghai            | 23:30:45 | 2026-05-15 | UTC+08:00
Australia/Sydney         | 01:30:45 | 2026-05-15 | UTC+10:00
UTC                      | 15:30:45 | 2026-05-14 | UTC+00:00

============================================================
```

### GUI Features
- Real-time updates every second
- Color-coded information (times in green, timezones in cyan, offsets in gold)
- Individual delete buttons for each timezone
- Input field to add new timezones
- Reset to default button

## Timezone Examples

Valid timezone strings:
```
'UTC', 'US/Eastern', 'US/Pacific', 'Europe/London', 'Europe/Paris',
'Asia/Tokyo', 'Asia/Shanghai', 'Asia/Kolkata', 'Australia/Sydney',
'Africa/Cairo', 'America/New_York', 'America/Los_Angeles', etc.
```

To find a timezone:
```python
from digital_clock import DigitalClock

clock = DigitalClock()
all_timezones = clock.list_available_timezones()

# Search for timezones
india_zones = [tz for tz in all_timezones if 'India' in tz]
print(india_zones)  # ['Asia/Kolkata']
```

## Advanced Usage

### Custom Configuration
```python
from digital_clock import DigitalClock

# Create with specific timezones only
custom_zones = ['US/Pacific', 'Europe/London', 'Asia/Tokyo']
clock = DigitalClock(time_zones=custom_zones)

# Get detailed info
info = clock.get_timezone_info('Asia/Tokyo')
print(f"Current time: {info['current_time']}")
print(f"Is DST active: {info['is_dst']}")
print(f"UTC Offset: {info['utc_offset']}")
```

### Continuous Display
```python
from digital_clock import DigitalClock
import time

clock = DigitalClock()

while True:
    print(clock.display_clock())
    time.sleep(60)  # Update every minute
```

## License

This project is open source and available for personal and educational use.

## Contributing

Feel free to enhance this project by:
- Adding more features (alerts, alarms, etc.)
- Improving the UI design
- Adding support for different time formats
- Creating web-based version

# lookbusy 

## About

`lookbusy` is a lightweight Linux terminal utility that simulates high-activity "hacker-style" logs. Usefull for background aesthetics or looking busy when someone walks past your desk.

* **Current Version:** `v0.0.1-alpha`  
* **Status:** `Experimental` - This utility is in early development. Features may be added, removed, or broken at any time.
 
## Screenshots

![lookbusy crypto](assets/crypto.gif)

![lookbusy proxy](assets/proxy.gif)

## Usage

Run the executable followed by the module name you wish to simulate:
``` bash
lookbusy <module> [speed]
```

To stop the text generation, simply use `CTRL+C` to "abort the process!".

### Modules

* `crypto` - Simulates a high-speed multi-algo cryptocurrency miner with share submission.
* `proxy` - Validates SOCKS5/HTTP nodes with realistic latency and success/fail rates.
* `network` - Streams realistic TCP/HTTP packet capture logs and API requests.
* `ml` - Displays ResNet-152 deep learning model training epochs and accuracy jitter.
* `packages` - Simulates APT-style system updates, dependency building, and unpacking.
* `random` - Picks one of the above modules at random.

### Speed Settings

* `--normal` - 1x speed
* `--fast` - 2x speed
* `--slow` - 10x speed

## Installation

Since `lookbusy` uses standard C libraries, you only need `gcc` to get it running.

1. **Clone the repository:**
   ```bash
   git clone https://github.com/daniel-meek/lookbusy.git
   cd lookbusy
   ```
2. **Compile the source:**
   ``` bash
   gcc -o lookbusy main.c
   ```
3. **(Optional) Install to your path:**
   ``` bash
   sudo mv lookbusy /usr/local/bin/
   ```

## Changelog

### v0.0.1-alpha - 2026-04-05
- Initial commit with 5 modules, speed settings, and simple error handling.

## Author

Developed with ☕ by @daniel-meek

## License

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for the full text.
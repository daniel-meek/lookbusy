# idlegen 

A lightweight Linux terminal utility that simulates high-activity "hacker-style" logs. Usefull for background aesthetics or looking busy when someone walks past your desk.

* **Current Version:** `v0.0.1-alpha`  
* **Status:** `Experimental` - This utility is in early development. Features may be added, removed, or broken at any time.
 
# Screenshots

![idlegen crypto](assets/crypto.gif)

![idlegen proxy](assets/proxy.gif)

## Installation

Since `idlegen` uses standard C libraries, you only need `gcc` to get it running.

1. **Clone the repository:**
   ```bash
   git clone https://github.com/daniel-meek/idlegen.git
   cd idlegen
   ```
2. **Compile the source:**
   ``` bash
   gcc -o idlegen main.c
   ```
3. **(Optional) Install to your path:**
   ``` bash
   sudo mv idlegen /usr/local/bin/
   ```

## Usage

Run the executable followed by the module name you wish to simulate:
``` bash
idlegen <module>
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

## License

This project is open-source and available under the [MIT License](https://www.google.com/search?q=LICENSE).

## Changelog

### v0.0.1-alpha - 2026-04-05
- Initial commit with 5 modules, speed settings, and simple error handling.

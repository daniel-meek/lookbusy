# lookbusy 

## About

`lookbusy` is a lightweight Linux terminal utility that simulates high-activity "hacker-style" logs. Usefull for background aesthetics or looking busy when someone walks past your desk.

* **Current Version:** `v0.0.3-experimental` 
* **Status:** `Experimental` - This utility is in early development. Features may be added, removed, or broken at any time.
 
## Screenshots

<div align="center">
  <img src="assets/crypto.gif" width="90%" alt="Crypto module" />
  <br>
  <img src="assets/proxy.gif" width="90%" alt="Proxy module" />
  <br>
  <img src="assets/network.gif" width="90%" alt="Network module" />
</div>

## Usage

Run the executable followed by the module name you wish to simulate:

``` bash
lookbusy <module> [speed]
```

To stop the text generation, simply use `CTRL+C` to "abort the process!".

### Modules

* `crypto` - Simulates a high-speed, multi-GPU cryptocurrency mining rig with real-time hash rates, nonce discovery, and thermal diagnostics.
* `proxy` - Runs a massive, high-concurrency proxy scanner, blasting through IP blocks with authentic timeout, refusal, and success rates.
* `network` -Emulates a deep packet inspection (DPI) firewall, streaming rapid TCP/IP packet captures and isolating suspicious hex payloads.
* `ml` - Simulates a dynamic machine learning pipeline, complete with dataset loading, hardware allocation, and colorized epoch training logs.
* `packages` - Faithfully recreates the Debian/Ubuntu apt installation experience, complete with dynamic dependency trees, unpacking, and sticky progress bars.
* `random` - Picks one of the above modules at random.

### Speed Settings

* `-s, --speed [float]` - Sets the speed of the wait function.

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

### v0.0.3-experimental - 2026-04-10

- Implemented variable speed settings.
- Added short flag for help `-h, --help`, about `-a, --about`, and version `-v, --version`.
- Added variable lenght to final hex dump row.
- Rebranded from "alpha" to "experimental" to better reflect the project state.

### v0.0.2-experimental - 2026-04-05

- Overhaul for all modules.
  - `package`: Added sticky [Working] progress bars and exact apt styling.
  - `network`: Rebuilt as a tcpdump-style packet sniffer with 16-byte hex dumps.
  - `ml`: Introduced dynamic architectures (Deep Learning vs. Ensembles) and colorized training metrics.
  - `crypto`: Switched to a high-speed multi-GPU threading simulation.
  - `proxy`: Increased concurrency payload to simulate a real masscan operation.
- Fixed speed flag bugs.
- Added `--help`, `--about`, and `--version`

### v0.0.1-experimental - 2026-04-05
- Initial commit with 5 modules, speed settings, and simple error handling.

## Author

Developed **with** ☕ by @daniel-meek

## License

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for the full text.
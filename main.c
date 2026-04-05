/*
 * ---------------------------------------------------------
 * PROJECT: lookbusy
 * DESCRIPTION: Linux terminal nonsense generator. "Because looking busy is 90% of the job."
 * VERSION: 0.0.1-alpha
 * DATE: 2026-04-05
 * AUTHOR: Daniel Meek (https://github.com/daniel-meek)
 * STAGE: Experimental
 * LICENSE: MIT
 * ---------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

// ---------------------------------------------------------
// HELPER FUNCTIONS
// ---------------------------------------------------------

#define CLR_RED     "\033[0;31m"
#define CLR_GREEN   "\033[0;32m"
#define CLR_YELLOW  "\033[0;33m"
#define CLR_BLUE    "\033[0;34m"
#define CLR_MAGENTA "\033[0;35m"
#define CLR_CYAN    "\033[0;36m"
#define CLR_WHITE   "\033[0;37m"

#define CLR_RESET   "\033[0m"

#define CURSOR_SHOW "\033[?25h"
#define CURSOR_HIDE "\033[?25l"

float speed_factor = 1.0; // Global speed factor

// Helper function to sleep for milliseconds *modified by speed_factor
void msleep(int ms) {
    usleep((int)(ms * speed_factor) * 1000);
}

void get_time(char *buf) {
    time_t raw;
    struct tm *info;
    time(&raw);
    info = localtime(&raw);
    strftime(buf, 22, "[%Y-%m-%d %H:%M:%S]", info);
}

// Handle the missing cursor after ctrl+c bug. 
void handle_sigint(int sig) {
    // "\033[?25h" to show cursor again.
    char t[22];
    
    get_time(t);
    printf("\n\n%s%s [%sSYSTEM%s] %sPROCESS ABORTED!%s \n", 
           t, CURSOR_SHOW, 
           CLR_YELLOW, CLR_RESET,  
           CLR_RED, CLR_RESET);
    printf("%s [%sSYSTEM%s] Default environment restored.\n\n",
           t,
           CLR_YELLOW, CLR_RESET);
    exit(0);
}


// ---------------------------------------------------------
// MODULE IMPLEMENTATION
// 
// cryptominer - 
// proxy - 
// network - 
// ml - 
// packages -
// ---------------------------------------------------------

void module_cryptominer() {
    const char *algos[] = {
        "SHA-256d", "Ethash", "Scrypt", "X11", "RandomX", "KawPow", "Equihash"
    };

    const char *fluff[] = {
        "Initializing CUDA kernels... OK",
        "Setting GPU memory clock to 7001 MHz",
        "Detected LHR lock - adjusting auto-tune...",
        "Applying memory timings to Device #0",
        "Stratum protocol: handshaking with pool...",
        "Fetching new difficulty target from master...",
        "Temperature Check: GPU0: 64C, GPU1: 61C",
        "Fan speed optimized at 45%% (Auto)",
        "Memory allocation: 4.2GB DAG loaded",
        "Re-syncing local block height with network...",
        "Warning: Minor stale share detected (0.2%%)",
        "Tuning intensity level: 24 (Aggressive)",
        "Heartbeat sent to monitor.mockcrypto.com",
        "CPU threads isolated for RandomX verification",
        "Switching to backup failover pool...",
        "Validating nonce range 0x00000000 -> 0xFFFFFFFF",
        "Kernel overhead optimized: 0.12ms",
        "API Server listening on 127.0.0.1:4067",
        "Power draw: 145W (Efficiency: 0.42 MH/W)",
        "Thermal throttling: CPU1 core clock reduced"
    };

    const char *diag_reports[] = {
        "VRAM Integrity Scan: 0 parity errors detected",
        "Cooling Loop Status: Fluid pressure nominal (1.2 bar)",
        "Stratum keep-alive: Latency stable at 38ms",
        "Recalculating hash-tree root for next epoch...",
        "GPU Driver Telemetry: P-State P0 (Maximum Performance)",
        "NTC Thermistor Check: Hotspot delta < 12C",
        "Clearing stale DAG buffers from PCIe bus...",
        "Syncing local wallet balance with pool API...",
        "Core Voltage Offset: -125mV (Undervolt Stable)",
        "Memory Controller Load: 94% (Non-blocking)",
        "Entropy pool replenished for nonce generation",
        "Hardware ID: [GPU-bd04-f2a1] verified by server"
    };

    int ports[] = {80, 8080, 3128, 1080, 8000, 999, 5678, 4153, 1081, 1082, 6779, 6515, 5757, 7771, 8127, 8315, 8062, 6300, 8989, 8001};

    char t[22];
    char hash[65];
    const char hex_chars[] = "0123456789abcdef";
    hash[64] = '\0';

    while(1) {
        // RANDOM FLUFF STAGE
        int fluff_count = 2 + (rand() % 4); // generates 2, 3, 4, or 5
        for(int f=0; f < fluff_count; f++) {
            get_time(t);
            printf("%s [%sSYSTEM%s] %s\n", t, CLR_YELLOW, CLR_RESET, fluff[rand() % 20]);
            
            int delay = 1000 + (rand() % 6000);
            msleep(delay);
        }

        // NEW JOB STAGE 
        int ip1 = 1 + rand() % 223, ip2 = rand() % 255, ip3 = rand() % 255, ip4 = 1 + rand() % 254;
        int diff = 10000000 + (rand() % 89999999); 
        int chunks = 32 + (rand() % 98); // 32 to 128
        const char* algo = algos[rand() % 7];

        printf("\n%s [%sSYSTEM%s] Connecting to %s%d.%d.%d.%d%s...\n",
               t, CLR_YELLOW, CLR_RESET,
               CLR_WHITE, ip1, ip2, ip3, ip4, CLR_RESET);

        int wait_seconds = 10 + (rand() % 30); // 10 to 40 seconds
        msleep(wait_seconds * 1000);

        get_time(t);
        printf("%s [%sNEW JOB%s] FROM %s%d.%d.%d.%d%s DIFF %s%d%s ALGO %s%s%s CHUNKS %s%d%s\n", 
               t, CLR_MAGENTA, CLR_RESET, 
               CLR_WHITE, ip1, ip2, ip3, ip4, CLR_RESET, 
               CLR_WHITE, diff, CLR_RESET, 
               CLR_WHITE, algo, CLR_RESET, 
               CLR_WHITE, chunks, CLR_RESET);
        msleep(800);

        // HASHING STAGE
        for(int c=1; c <= chunks; c++) {
            for(int i=0; i<64; i++) hash[i] = hex_chars[rand() % 16];
            float hashrate = 50.0f + (rand() % 100) / 10.0f;
            
            get_time(t);
            printf("%s [%sMINER%s] [%s%.1f MH/s%s] Hashing chunk %d/%d... %s\n", 
                   t, CLR_CYAN, CLR_RESET, 
                   CLR_GREEN, hashrate, CLR_RESET, 
                   c, chunks, hash);
            fflush(stdout);
            msleep(400 + (rand() % 600)); // Adjusted for better scroll feel
        }

        // SUCCESS STAGE 
        get_time(t);
        printf("\n%s [%sSYSTEM%s] %sBlock found!%s Submitting share...\n", t, CLR_YELLOW, CLR_RESET, CLR_GREEN, CLR_RESET);
        msleep(1200);
        
        get_time(t);
        printf("%s [%sSYSTEM%s] %sShare ACCEPTED.%s (+0.000%d MOCK)\n\n", 
               t, CLR_YELLOW, CLR_RESET, CLR_GREEN, CLR_RESET, 100 + (rand() % 899));
        msleep(2500);

        // DIAGNOSTICS STAGE
        int diag_count = 3 + (rand() % 3); // Show 3 to 5 diag lines
        for(int d=0; d < diag_count; d++) {
            get_time(t);
            int temp = 55 + (rand() % 20);
            int fan = 35 + (rand() % 30);
            printf("%s [%sSYSTEM%s] [%sDIAG%s] %s (Temp: %s%dC%s | Fan: %s%d%%%s)\n", 
                   t, CLR_YELLOW, CLR_RESET, 
                   CLR_MAGENTA, CLR_RESET, diag_reports[rand() % 12], 
                   CLR_WHITE, temp, CLR_RESET, 
                   CLR_WHITE, fan, CLR_RESET);
            msleep(1500 + (rand() % 2000));
        }
        printf("\n");
    }
}

void module_proxy() {
    const char *fluff[] = {
        "Rotating circuit headers for anonymity...",
        "Syncing local database with master proxy list...",
        "Verifying SSL certificates against known CAs...",
        "Testing latency overhead for SOCKS5 tunneling...",
        "Cleaning stale socket connections...",
        "Refreshing peer-to-peer relay nodes...",
        "Reading proxies from /usr/share/dirb/common/proxies.txt",
        "Loading nodes from /usr/share/dirb/common/nodes.list",
        "Updating geo-location database for IP mapping...",
        "Handshaking with upstream SOCKS5 gateway...",
        "Purging blacklisted exit nodes from cache...",
        "Re-routing traffic through encrypted tunnel (AES-256-GCM)...",
        "Synchronizing clock with NTP pool servers...",
        "Validating upstream SOCKS5 handshake protocols...",
        "Scanning for available high-bandwidth exit nodes..."
    };

    char t[22];

    while (1) {
        
        // FLUFF STAGE
        int total_proxies = 8 + (rand() % (256 - 8 + 1)); // Range between 8 and 256
        int current_count = 1;
        int valid_count = 0;
        int broken_count = 0;

        get_time(t);

        printf("%s [%sSYSTEM%s] %s\n", t, CLR_YELLOW, CLR_RESET, fluff[rand() % 15]);
        msleep(600 + (rand() % 600));
        printf("%s [%sSYSTEM%s] %s\n", t, CLR_YELLOW, CLR_RESET, fluff[rand() % 15]);
        msleep(1000 + (rand() % 800));
        printf("%s [%sSYSTEM%s] Starting verification of %d nodes...\n\n", t, CLR_YELLOW, CLR_RESET,total_proxies);
        msleep(100);

        // VERIFICATION STAGE
        while (current_count <= total_proxies) {
            int ip1 = 1 + rand() % 223, ip2 = rand() % 255, ip3 = rand() % 255, ip4 = 1 + rand() % 254;
            int ports[] = {80, 8080, 3128, 1080, 8000, 999, 5678, 4153, 1081, 1082, 6779, 6515, 5757, 7771, 8127, 8315, 8062, 6300, 8989, 8001};
            int port = ports[rand() % 20];
            int is_valid = (rand() % 100 < 80);

            // Logic for timing - 95% are fast (0.5s-2s), 5% are slow (up to 5s-30s)
            if (rand() % 5 == 0) {
                msleep(5000 + rand() % 25000); // Slow
            } else {
                msleep(500 + rand() % 1500); // Fast
            }

            if (is_valid) {
                valid_count++;
                
                printf("[%s!%s] %sValid proxy  %s: %s%d.%d.%d.%d:%d%s #%d (Checked %d/%d: %s%d%s/%d Valid proxies)\n",
                       CLR_GREEN, CLR_RESET, CLR_GREEN, CLR_RESET, CLR_WHITE, ip1, ip2, ip3, ip4, port, CLR_RESET, current_count, current_count, total_proxies, CLR_GREEN, valid_count, CLR_RESET, total_proxies);
            } else {
                broken_count++;

                printf("[%sX%s] %sBroken proxy %s: %s%d.%d.%d.%d:%d%s #%d (Checked %d/%d: %s%d%s/%d Invalid proxies)\n",
                       CLR_RED, CLR_RESET, CLR_RED, CLR_RESET, CLR_WHITE, ip1, ip2, ip3, ip4, port, CLR_RESET, current_count, current_count, total_proxies, CLR_RED, broken_count, CLR_RESET, total_proxies);
            }

            current_count++;
        }

        printf("\n%s [%sSYSTEM%s] Verification complete. %s%d%s valid / %s%d%s dropped.\n",
              t, CLR_YELLOW, CLR_RESET,
              CLR_GREEN, valid_count, CLR_RESET,
              CLR_RED, broken_count, CLR_RESET);
        msleep(2000);
    }
}

void module_network() {
    const char *methods[] = {"GET", "POST", "PUT", "DELETE", "OPTIONS", "PATCH"};
    const char *paths[] = {"/api/v1/data", "/images/logo.png", "/auth/login", "/styles.css", "/metrics", "/ws", "/system/health"};
    
    printf("Starting packet capture on interface eth0 (promiscuous mode)...\n");
    msleep(600);
    
    while(1) {
        int ip1 = 1 + rand() % 254, ip2 = rand() % 255, ip3 = rand() % 255, ip4 = 1 + rand() % 254;
        const char *method = methods[rand() % 6];
        const char *path = paths[rand() % 7];
        int status = (rand() % 15 == 0) ? (400 + rand() % 104) : (200 + rand() % 5); // Mostly 200s, some 4xx/5xx
        int ms = 5 + rand() % 150;
        int bytes = 200 + rand() % 8000;
        
        printf("[TCP] %d.%d.%d.%d - - [%s %s HTTP/1.1] %d %d bytes - %dms\n", 
               ip1, ip2, ip3, ip4, method, path, status, bytes, ms);
               
        msleep(30 + rand() % 150); // Fast stream
    }
}

void module_ml() {
    int epoch = 1;
    float loss = 3.5f;
    float accuracy = 0.12f;
    
    printf("Loading backend...\n");
    msleep(400);
    printf("Allocating VRAM (11452 MiB)...\n");
    msleep(800);
    printf("Initializing ResNet-152 architecture...\n");
    msleep(500);
    
    while(1) {
        int step_time = 10 + rand() % 15;
        printf("Epoch %d/5000 [=========================>] - %dms/step - loss: %.4f - accuracy: %.4f\n", 
               epoch, step_time, loss, accuracy);
        
        loss -= (float)(rand() % 100) / 10000.0f;
        if (loss < 0.005f) loss = 0.005f + (float)(rand() % 10) / 10000.0f; // Jitter at the bottom
        
        accuracy += (float)(rand() % 60) / 10000.0f;
        if (accuracy > 0.998f) accuracy = 0.995f + (float)(rand() % 30) / 10000.0f;
        
        epoch++;
        msleep(200 + rand() % 300);
    }
}

void module_packages() {
    const char *packages[] = {"libc6", "gcc-11", "python3-minimal", "linux-headers-generic", "nginx", "docker-ce", "htop", "curl", "libssl-dev", "bash", "vim-common", "openvswitch-switch"};
    int pkg_count = sizeof(packages) / sizeof(packages[0]);
    
    printf("Reading package lists... Done\n");
    msleep(400);
    printf("Building dependency tree... Done\n");
    msleep(300);
    printf("Reading state information... Done\n");
    msleep(500);
    printf("Calculating upgrade... Done\n");
    msleep(200);
    
    int get_counter = 1;
    while(1) {
        int pkg_idx = rand() % pkg_count;
        float size_mb = (float)(10 + rand() % 500) / 10.0f;
        
        printf("Get:%d http://archive.ubuntu.com/ubuntu focal/main amd64 %s [%.1f MB]\n", get_counter++, packages[pkg_idx], size_mb);
        
        // Render fake progress bar
        for (int p = 0; p <= 100; p += 10 + rand() % 25) {
            if (p > 100) p = 100;
            int bars = p / 5; // 20 character wide bar
            printf("\r[");
            for(int b=0; b<20; b++) {
                if (b < bars) printf("#");
                else printf(" ");
            }
            printf("] %d%%", p);
            fflush(stdout); // Force print without newline
            msleep(100 + rand() % 200);
        }
        printf("\nUnpacking %s (1.0.%d-ubuntu1)...\n", packages[pkg_idx], rand() % 100);
        msleep(150 + rand() % 200);
        printf("Setting up %s...\n", packages[pkg_idx]);
        msleep(200 + rand() % 300);
    }
}

// ---------------------------------------------------------
// CORE FRAMEWORK
// ---------------------------------------------------------

// Define the module structure
typedef struct {
    const char *name;
    const char *description;
    void (*func)();
} ActivityModule;

// Register all modules here
ActivityModule modules[] = {
    {"crypto",   "Simulates a high-speed cryptocurrency miner", module_cryptominer},
    {"proxy",    "Simulates a proxy server validator with success/fail rates", module_proxy},
    {"network",  "Prints realistic incoming and outgoing HTTP/TCP traffic", module_network},
    {"ml",       "Simulates deep learning model training output", module_ml},
    {"packages", "Simulates fetching, downloading, and installing system updates", module_packages}
};
int num_modules = sizeof(modules) / sizeof(modules[0]);

void print_help(const char *prog_name) {
    printf("Usage: %s <module>\n\n", prog_name);
    printf("Available modules:\n");
    for (int i = 0; i < num_modules; i++) {
        printf("  %-10s : %s\n", modules[i].name, modules[i].description);
    }
    printf("  %-10s : Pick a random module\n", "random");
}

int main(int argc, char *argv[]) {
    // CTRL+C Handler
    signal(SIGINT, handle_sigint);
    
    // Random number for random module
    srand(time(NULL));

    if (argc < 2) {
        print_help(argv[0]);
        return 1;
    }

    const char *target_module = NULL;

    // Loop through arguments to find speed flags and the module name
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--normal") == 0) {
            speed_factor = 1.0; // normal
        } else if (strcmp(argv[i], "--fast") == 0) {
            speed_factor = 0.5; // 2x faster
        } else if (strcmp(argv[i], "--faster") == 0) {
            speed_factor = 0.1; // 10x faster
        } else {
            // If it's not a speed flag, it's a module
            target_module = argv[i];
        }
    }

    if (target_module == NULL) {
        printf("Error: No module specified.\n");
        print_help(argv[0]);
        return 1;
    }

    // Handle 'random' logic
    if (strcmp(target_module, "random") == 0) {
        target_module = modules[rand() % num_modules].name;
    }

    // Module execution loop... (keep your existing logic here)
    for (int i = 0; i < num_modules; i++) {
        if (strcmp(target_module, modules[i].name) == 0) {
            printf("\033[?25l"); // Hide cursor
            modules[i].func();
            return 0;
        }
    }

    printf("Error: Module '%s' not found.\n", target_module);
    return 1;
}
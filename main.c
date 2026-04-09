/*
 * ---------------------------------------------------------
 * PROJECT: lookbusy
 * DESCRIPTION: Linux terminal nonsense generator.
 * VERSION: 0.0.2-alpha
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

#define APP_VERSION "0.0.2-alpha"
#define APP_AUTHOR "daniel-meek"
#define APP_REPO "https://github.com/daniel-meek/lookbusy"

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

// Function to sleep for milliseconds *modified by speed_factor
void msleep(int ms) {
    usleep((int)(ms * speed_factor) * 1000);
}

// Function to get a formatted timestamp string
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

 
// Function to draw a realistic APT-style progress bar
void draw_apt_progress(int current, int total, const char *operation) {
    int percent = (current * 100) / total;
    if (percent > 100) percent = 100;
    
    // \r moves to start of line, \033[K clears the current line
    printf("\r\033[K%s %3d%% [%s]%s", CLR_YELLOW, percent, operation, CLR_RESET);
    fflush(stdout);
}


// ---------------------------------------------------------
// MODULE IMPLEMENTATION
// - cryptominer
// - proxy
// - network 
// - ml
// - packages
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
        int fluff_count = 2 + (rand() % 4); // get 2-5 fluff messages
        for(int f=0; f < fluff_count; f++) {
            get_time(t);
            printf("%s [%sSYSTEM%s] %s\n", t, CLR_YELLOW, CLR_RESET, fluff[rand() % 20]);
            
            int delay = 800 + (rand() % 3000);
            msleep(delay);
        }

        // NEW JOB STAGE 
        int ip1 = 1 + rand() % 223, ip2 = rand() % 255, ip3 = rand() % 255, ip4 = 1 + rand() % 254;
        int diff = 10000000 + (rand() % 89999999); 
        const char* algo = algos[rand() % 7];

        printf("\n%s [%sSYSTEM%s] Connecting to %s%d.%d.%d.%d%s...\n", t, CLR_YELLOW, CLR_RESET, CLR_WHITE, ip1, ip2, ip3, ip4, CLR_RESET);
        msleep(800 + (rand() % 3000)); 

        get_time(t);
        printf("%s [%sNEW JOB%s] FROM %s%d.%d.%d.%d%s DIFF %s%d%s ALGO %s%s%s\n", 
               t, CLR_MAGENTA, CLR_RESET, CLR_WHITE, ip1, ip2, ip3, ip4, CLR_RESET, 
               CLR_WHITE, diff, CLR_RESET, CLR_WHITE, algo, CLR_RESET);
        msleep(400);

        // HASHING STAGE
        int hash_bursts = 60 + (rand() % 90); // 60 to 150 hashes flying by
        for(int h=0; h < hash_bursts; h++) {
            for(int i=0; i<64; i++) hash[i] = hex_chars[rand() % 16];
            int gpu_id = rand() % 4; // Simulate 4 GPUs working
            unsigned int nonce = (unsigned int)(rand() * rand());
            float hashrate = 80.0f + (rand() % 400) / 10.0f;
            
            get_time(t);
            // Example: [GPU-2] 112.4 MH/s | Nonce: 0x4f8a1b2c -> e3b0c442...
            printf("%s [%sGPU-%d%s] %s%.1f MH/s%s | Nonce: %s0x%08x%s -> %s\n", 
                   t, CLR_CYAN, gpu_id, CLR_RESET, 
                   CLR_GREEN, hashrate, CLR_RESET, 
                   CLR_YELLOW, nonce, CLR_RESET, hash);
            
            msleep(50 + (rand() % 100)); // Incredible speed
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
            msleep(500 + (rand() % 2000));
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

        int total_proxies = 8 + (rand() % (256 - 8 + 1)); // Range between 8 and 256
        int current_count = 1;
        int valid_count = 0;
        int broken_count = 0;

        // FLUFF STAGE
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

            // Logic for timing - 95% are fast (0.1s-1s), 5% are slow (up to 5s-10s)
            if (rand() % 100 < 5) {
                msleep(5000 + rand() % 5000); // Slow
            } else {
                msleep(100 + rand() % 900);   // Fast
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
        msleep(500 + (rand() % 500));
    }
}

void module_network() {
    const char *fluff[] = {
        "Attaching BPF filter to interface eth0...",
        "Setting eth0 to promiscuous mode...",
        "Listening on eth0, link-type EN10MB (Ethernet)",
        "Resolving reverse DNS for external nodes...",
        "TCP state engine synchronized with stream",
        "Reassembling fragmented IPv4 payload...",
        "Analyzing deep packet inspection (DPI) signatures...",
        "Flushing ARP cache for stale MAC addresses...",
        "Synchronizing local clock with NTP pool...",
        "Applying strict routing policies to incoming stream..."
    };

    const char *errors[] = {
        "Warning: Kernel ring buffer full, dropping packets",
        "Error: Bad checksum on IPv4 header from upstream",
        "Node timeout: Peer unreachable on routing table",
        "Port scan detected from external gateway!",
        "RST received: Connection forcefully refused by host"
    };

    const char *dpi_alerts[] = {
            "Suspicious payload intercepted. Generating 16-byte hex dump...",
            "IDS alert triggered: Malformed TCP sequence. Dumping raw buffer...",
            "Anomalous routing signature detected. Extracting packet memory...",
            "Data exfiltration flag raised (Rule #402). Inspecting raw frame...",
            "Buffer overflow attempt blocked. Dumping hex for forensic analysis...",
            "Unrecognized protocol header. Initiating deep packet inspection...",
            "Encrypted tunnel handshake failed. Displaying raw socket buffer...",
            "Kernel diagnostic: Invalid MTU frame size. Hex dump follows..."
    };

    const char *stream_errors[] = {
        "CHECKSUM_FAIL", "TTL_EXCEEDED", "FRAG_DROPPED", "MALFORMED_HDR", "SEQ_MISMATCH"
    };

    const char *flags[] = {"[S]", "[P.]", "[.]", "[S.]", "[R]", "[F.]"};
    int target_ports[] = {80, 443, 22, 3389, 8080, 53, 3306, 6379, 21, 23};
    char t[22];

    while (1) {

        // FLUFF / ERROR STAGE 
        int fluff_count = 2 + (rand() % 7); // Generates 2 to 8
        for (int f = 0; f < fluff_count; f++) {
            get_time(t);
            int is_err = (rand() % 10 < 2); // 20% chance for an error
            
            if (is_err) {
                printf("%s [%sERROR%s]  %s%s%s\n", t, CLR_RED, CLR_RESET, CLR_RED, errors[rand() % 5], CLR_RESET);
            } else {
                printf("%s [%sSYSTEM%s] %s\n", t, CLR_YELLOW, CLR_RESET, fluff[rand() % 10]);
            }
            msleep(400 + (rand() % 600));
        }
        printf("\n");
        msleep(500);


        // NETWORK STREAM STAGE
        const char *stream_errors[] = {"CHECKSUM_FAIL", "TTL_EXCEEDED", "FRAG_DROPPED", "MALFORMED_HDR", "SEQ_MISMATCH"};
        
        int packet_count = 32 + (rand() % 225); // Generates 32 to 256
        for (int p = 0; p < packet_count; p++) {
            get_time(t);
            
            int ip1 = 1 + rand() % 223, ip2 = rand() % 255, ip3 = rand() % 255, ip4 = 1 + rand() % 254;
            int sport = 1024 + rand() % 60000;
            int tip4 = 30 + (rand() % 40); // Internal subnet target
            int dport = target_ports[rand() % 10];
            
            const char* flag = flags[rand() % 6];
            unsigned int seq = (unsigned int)(rand() * rand());
            int win = 1024 + (rand() % 64000);
            int len = (rand() % 4 == 0) ? 0 : (16 + (rand() % 1400)); 
            
            // 5% chance to throw an inline error frame
            if (rand() % 100 < 5) {
                printf("%s %sIP%s %s%d.%d.%d.%d:%d%s > %s172.18.45.%d:%d%s: %s[ERROR: %s]%s seq %u, len %d\n",
                       t, CLR_CYAN, CLR_RESET,
                       CLR_WHITE, ip1, ip2, ip3, ip4, sport, CLR_RESET,
                       CLR_GREEN, tip4, dport, CLR_RESET,
                       CLR_RED, stream_errors[rand() % 5], CLR_RESET, seq, len);
            } else {
                printf("%s %sIP%s %s%d.%d.%d.%d:%d%s > %s172.18.45.%d:%d%s: Flags %s%s%s, seq %u, win %d, length %d\n",
                       t, CLR_CYAN, CLR_RESET,
                       CLR_WHITE, ip1, ip2, ip3, ip4, sport, CLR_RESET,
                       CLR_GREEN, tip4, dport, CLR_RESET,
                       CLR_MAGENTA, flag, CLR_RESET, seq, win, len);
            }
            
            msleep(25 + (rand() % 250)); // short sleep for many messages a second
        }
        printf("\n");
        
        // HEX DUMP STAGE
        get_time(t);
        printf("%s [%sDPI%s] %s\n", t, CLR_YELLOW, CLR_RESET, dpi_alerts[rand() % 8]);
        msleep(400);

        int dump_rows = 8 + (rand() % 17); // Generates 8 to 24 rows
        int offset = 0;
        
        for (int r = 0; r < dump_rows; r++) {
            printf("      %s%04x%s | ", CLR_YELLOW, offset, CLR_RESET);
            
            unsigned char chunk[16];
            
            // The final row will have a random cut-off between 1 and 15 bytes
            int bytes_in_row = 16;
            if (r == dump_rows - 1) {
                bytes_in_row = 1 + (rand() % 15); 
            }
            
            // Print Hexadecimal Bytes
            for (int b = 0; b < 16; b++) {
                if (b < bytes_in_row) {
                    chunk[b] = rand() % 256;
                    printf("%02x ", chunk[b]);
                } else {
                    // Pad missing bytes 
                    printf("   "); 
                }
                
                if (b == 7) printf(" "); // Standard 8-byte visual gap
            }
            
            printf("| ");
            
            // Print ASCII Decoding (Only print up to the actual bytes in this row)
            for (int b = 0; b < bytes_in_row; b++) {
                char c = chunk[b];
                if (c >= 32 && c <= 126) {
                    printf("%s%c%s", CLR_CYAN, c, CLR_RESET);
                } else {
                    printf(".");
                }
            }
            printf("\n");
            
            offset += bytes_in_row; // Increment offset by actual bytes printed
        }

        int hold_time = 5000 + (rand() % 15000); // hold for 5-20s
        msleep(hold_time); 
        printf("\n");
        
    }
}

void module_ml() {
    const char *frameworks[] = {"PyTorch 2.1.0", "TensorFlow 2.14", "JAX 0.4.13", "scikit-learn 1.3.0", "XGBoost 2.0.0"};
    const char *datasets[] = {"ImageNet-1K", "COCO-2017", "WikiText-103", "Kaggle-Titanic", "CelebA-HQ", "OpenAssistant-Guanaco"};
    const char *extensions[] = {".h5", ".pt", ".safetensors", ".pkl", ".onnx"};

    const char *ml_fluff[] = {
            "Compiling custom CUDA kernels for tensor operations...",
            "Downloading pre-trained weights from Hugging Face Hub...",
            "Tokenizing input text with Byte-Pair Encoding (BPE)...",
            "Applying data augmentation (RandomCrop, ColorJitter)...",
            "Balancing class weights using SMOTE...",
            "Freezing base neural layers for transfer learning...",
            "Initializing AdamW optimizer with weight decay 0.01...",
            "Setting up learning rate scheduler (Cosine Annealing)...",
            "Verifying tensor shapes: [BatchSize, Channels, Height, Width]...",
            "Dropping NaN values and interpolating missing features...",
            "Normalizing gradient values to [-1, 1] range...",
            "Shuffling DataLoader with random seed 42...",
            "Initializing Distributed Data Parallel (DDP) node...",
            "Checking gradient clipping thresholds (max_norm=1.0)...",
            "Loading GloVe 300d word embeddings into memory...",
            "Applying dropout (p=0.5) to fully connected layers...",
            "Optimizing computation graph with TensorRT...",
            "Validating early stopping patience criteria (patience=5)...",
            "Configuring WandB daemon for remote experiment tracking...",
            "Computing TF-IDF matrices for sparse representations..."
        };

    // Structure to hold different ML architectures
    struct MLTask {
        const char *model_name;
        const char *task_type;
        int is_deep_learning; // 1 for epochs/progress bar, 0 for ensemble/trees
    };

    struct MLTask tasks[] = {
        {"ResNet-152", "Image Classification", 1},
        {"YOLOv8x", "Object Detection", 1},
        {"BERT-Large", "Masked Language Modeling", 1},
        {"StyleGAN3", "Image Generation", 1},
        {"RandomForest", "Tabular Classification", 0},
        {"XGBoost-Dart", "Gradient Boosting", 0},
        {"Llama-3-8B-Instruct", "Causal LM (LoRA Fine-tuning)", 1}
    };

    char t[22];

    while (1) {
        int task_idx = rand() % 7;
        struct MLTask current_task = tasks[task_idx];
        
        // INITIALIZATION & DATA PIPELINE
        get_time(t);
        printf("%s [%sML-OPS%s] Initializing %s backend...\n", t, CLR_MAGENTA, CLR_RESET, frameworks[rand() % 5]);
        msleep(400 + rand() % 400);
        
        get_time(t);
        printf("%s [%sML-OPS%s] Loading dataset pipeline: %s...\n", t, CLR_MAGENTA, CLR_RESET, datasets[rand() % 6]);
        msleep(800 + rand() % 1000);

        // Print 2 to 5 random ML fluff operations
        int fluff_count = 2 + (rand() % 4);
        for(int f = 0; f < fluff_count; f++) {
            get_time(t);
            printf("%s [%sML-OPS%s] %s\n", t, CLR_MAGENTA, CLR_RESET, ml_fluff[rand() % 20]);
            msleep(600 + (rand() % 1500)); // Variable delays as it "processes" the data
        }

        get_time(t);
        if (current_task.is_deep_learning) {
            printf("%s [%sSYSTEM%s] Allocating VRAM (CUDA:0) ... %s%d MiB Reserved%s\n", t, CLR_YELLOW, CLR_RESET, CLR_CYAN, 4000 + rand() % 16000, CLR_RESET);
        } else {
            printf("%s [%sSYSTEM%s] Allocating RAM (CPU-Nodes: %d) ... %s%d MiB Reserved%s\n", t, CLR_YELLOW, CLR_RESET, 8 + rand() % 24, CLR_CYAN, 2000 + rand() % 8000, CLR_RESET);
        }
        msleep(600);

        get_time(t);
        printf("%s [%sML-OPS%s] Building architecture: %s%s%s (%s)\n\n", t, CLR_MAGENTA, CLR_RESET, CLR_WHITE, current_task.model_name, CLR_RESET, current_task.task_type);
        msleep(1200);

        // TRAINING LOOP STAGE
        if (current_task.is_deep_learning) {
            int total_epochs = 5 + rand() % 25;
            float loss = 4.5f + (rand() % 200) / 100.0f;
            float accuracy = 0.10f;

            for (int epoch = 1; epoch <= total_epochs; epoch++) {
                printf("%sEpoch %d/%d%s\n", 
                    CLR_WHITE, epoch, total_epochs, CLR_RESET);
                
                int steps = 40 + rand() % 60;
                for (int step = 1; step <= steps; step++) {
                    int percent = (step * 100) / steps;
                    int bar_width = 30;
                    int filled = (percent * bar_width) / 100;
                    
                    // Keras-style progress bar using \r (Added spacing to match your style)
                    printf("\r Steps: %4d/%d [%s", step, steps, CLR_GREEN);
                    for(int i = 0; i < bar_width; i++) {
                        if (i < filled - 1) printf("=");
                        else if (i == filled - 1) printf(">");
                        else printf(".");
                    }
                    printf("%s] - %dms/step", CLR_RESET, 15 + rand() % 60);
                    fflush(stdout);
                    msleep(10 + rand() % 30); // Very fast step calculation
                }
                
                // Calculate realistic epoch improvements
                loss -= (float)(rand() % 150) / 1000.0f;
                if (loss < 0.05f) loss = 0.05f + (float)(rand() % 20) / 1000.0f; // Jitter
                
                accuracy += (float)(rand() % 80) / 1000.0f;
                if (accuracy > 0.995f) accuracy = 0.995f - (float)(rand() % 10) / 1000.0f;
                
                float val_loss = loss + (float)(rand() % 60) / 100.0f;
                float val_acc = accuracy - (float)(rand() % 60) / 100.0f;
                if (val_acc < 0.1f) val_acc = 0.1f + (float)(rand() % 50) / 100.0f;

                // Print the fully colorized metrics line
                printf(" | loss: %s%.4f%s | accuracy: %s%.4f%s | val_loss: %s%.4f%s | val_accuracy: %s%.4f%s\n", 
                       CLR_RED, loss, CLR_RESET,
                       CLR_GREEN, accuracy, CLR_RESET,
                       CLR_YELLOW, val_loss, CLR_RESET,
                       CLR_CYAN, val_acc, CLR_RESET);
                msleep(250);
            }
        } else {
            // Ensemble / Tree model training output
            int estimators = 100 + rand() % 400;
            printf("Training Ensemble Model (%d estimators)...\n", estimators);
            for (int i = 10; i <= estimators; i += 10) {
                float oob_error = 1.0f / (i * 0.1f) + (rand() % 10) / 100.0f;
                float gini = oob_error * 0.8f + (rand() % 5) / 100.0f;
                
                printf("Building trees: %s%3d%s / %d | OOB Error: %s%.4f%s | Gini Impurity: %.4f\n", 
                       CLR_CYAN, i, CLR_RESET, estimators, 
                       CLR_MAGENTA, oob_error, CLR_RESET, gini);
                msleep(80 + rand() % 100);
            }
        }

        // MODEL EXPORT STAGE
        printf("\n");
        get_time(t);
        printf("%s [%sSYSTEM%s] Training complete. Optimizing tensor graph...\n", t, CLR_YELLOW, CLR_RESET);
        msleep(1200);
        
        get_time(t);
        printf("%s [%sSYSTEM%s] %sSaved to disk:%s model_weights_epoch_final%s %s[OK]%s\n\n", 
               t, CLR_YELLOW, CLR_RESET, CLR_GREEN, CLR_RESET, extensions[rand() % 5], CLR_GREEN, CLR_RESET);
        
        // Long hold before the next model starts training
        msleep(4000 + rand() % 5000); 
    }
}

void module_package() {
    // Word pools to generate realistic Debian package names
    const char *prefixes[] = {
        "lib", "python3-", "golang-", "node-", "ruby-", "php8.1-", "gcc-11-", "firmware-", "linux-image-", "linux-headers-", "postgresql-", "mysql-server-", "nginx-module-", "apache2-", "libqt5", "libgtk-3-", "rust-", "haskell-", "perl-module-", "x11-", "fonts-", "docker-"
    };
    
    const char *bases[] = {
        "ssl", "crypto", "yaml", "json", "xml", "http", "ssh", "dbus", "systemd", "wayland", "mesa", "llvm", "glibc", "boost", "qt5", "gtk3", "core", "utils", "networking", "bluetooth", "wifi", "audio", "video", "render", "math", "physics", "ai", "ml", "tensor", "socket", "stream", "buffer", "memory", "fs", "disk", "usb", "pci", "auth", "crypt", "hash"
    };
    
    const char *suffixes[] = {
        "-dev", "-doc", "-common", "-bin", "-minimal", "-core", "-dbg", "1a", "2", "3", "4", "5", "6", "7", "8", "-ext", "-plugin", ""
    };

    char t[22];

    while (1) {
        int pkg_count = 20 + (rand() % 61); // Generates 20-80 packages per cycle
        
        // Arrays to hold the static list for this entire cycle
        char pkg_names[200][64];
        char pkg_versions[200][32];
        int pkg_sizes[200];
        int total_size_kb = 0;

        // GENERATE THE PACKAGE MANIFEST
        for (int i = 0; i < pkg_count; i++) {
            sprintf(pkg_names[i], "%s%s%s",
                    prefixes[rand() % (sizeof(prefixes)/sizeof(prefixes[0]))],
                    bases[rand() % (sizeof(bases)/sizeof(bases[0]))],
                    suffixes[rand() % (sizeof(suffixes)/sizeof(suffixes[0]))]);

            sprintf(pkg_versions[i], "%d.%d.%d-%dubuntu%d",
                    1 + rand() % 10, rand() % 20, rand() % 50, 1 + rand() % 5, 1 + rand() % 4);

            pkg_sizes[i] = 10 + (rand() % 4000); // 10kB to 4MB sizes
            total_size_kb += pkg_sizes[i];
        }


        // INITIALIZATION & DEPENDENCY TREE
        printf("\r\033[KReading package lists... ");
        fflush(stdout); msleep(360 + rand() % 480);
        printf("Done\n");

        printf("\r\033[KBuilding dependency tree... ");
        fflush(stdout); msleep(360 + rand() % 480);
        printf("Done\n");

        printf("\r\033[KReading state information... ");
        fflush(stdout); msleep(240 + rand() % 360);
        printf("Done\n");

        printf("The following NEW packages will be installed:\n  ");
        int line_len = 2;
        for (int i = 0; i < pkg_count; i++) {
            int len = strlen(pkg_names[i]);
            if (line_len + len + 1 > 80) {
                printf("\n  ");
                line_len = 2;
            }
            printf("%s ", pkg_names[i]);
            line_len += len + 1;
        }
        printf("\n");
        msleep(400);

        printf("0 upgraded, %d newly installed, 0 to remove and %d not upgraded.\n", pkg_count, rand() % 10);
        printf("Need to get %.1f MB of archives.\n", total_size_kb / 1024.0);
        printf("After this operation, %.1f MB of additional disk space will be used.\n", (total_size_kb * 2.8) / 1024.0);
        msleep(800 + rand() % 1000);

        // FETCHING STAGE
        int fetched_kb = 0;
        for (int i = 0; i < pkg_count; i++) {
            printf("\r\033[KGet:%d http://archive.ubuntu.com/ubuntu jammy/main amd64 %s amd64 %s [%d kB]\n",
                   i + 1, pkg_names[i], pkg_versions[i], pkg_sizes[i]);
            
            fetched_kb += pkg_sizes[i];
            // During fetch, APT usually just shows [Working]
            draw_apt_progress(fetched_kb, total_size_kb, "Working");
            
            int fetch_delay = (20 + (pkg_sizes[i] / 30)) * 1.2;
            msleep(fetch_delay); 
        }
        printf("\r\033[KFetched %.1f MB in %ds (%.1f MB/s)\n", total_size_kb / 1024.0, 3 + rand() % 8, (total_size_kb / 1024.0) / 3.0);
        msleep(600);

        printf("\r\033[KPreconfiguring packages ...\n");
        msleep(960);

        // UNPACKING STAGE

        int total_dpkg_steps = pkg_count * 2; // Unpack + Setup
        int current_step = 0;
        int db_files = 120000 + rand() % 50000; 
        char op_buf[256]; // Buffer to hold the dynamic operation text

        for (int i = 0; i < pkg_count; i++) {
            printf("\r\033[KSelecting previously unselected package %s:amd64.\n", pkg_names[i]);
            draw_apt_progress(current_step, total_dpkg_steps, "Working"); msleep(10);
            
            printf("\r\033[K(Reading database ... %d files and directories currently installed.)\n", db_files + i * (1 + rand() % 5));
            draw_apt_progress(current_step, total_dpkg_steps, "Working"); msleep(15);
            
            printf("\r\033[KPreparing to unpack .../%s_%s_amd64.deb ...\n", pkg_names[i], pkg_versions[i]);
            draw_apt_progress(current_step, total_dpkg_steps, "Working"); msleep(15);
            
            printf("\r\033[KUnpacking %s:amd64 (%s) ...\n", pkg_names[i], pkg_versions[i]);
            
            // Update the progress bar with the specific Unpack operation
            sprintf(op_buf, "Unpacking %s:amd64 (%s) ...", pkg_names[i], pkg_versions[i]);
            current_step++;
            draw_apt_progress(current_step, total_dpkg_steps, op_buf); 
            
            int unpack_delay = (35 + (pkg_sizes[i] / 20)) * 1.2;
            msleep(unpack_delay);
        }

        // INSTALLING STAGE
        for (int i = 0; i < pkg_count; i++) {
            printf("\r\033[KSetting up %s:amd64 (%s) ...\n", pkg_names[i], pkg_versions[i]);
            
            // Update the progress bar with the specific Setup operation
            sprintf(op_buf, "Setting up %s:amd64 (%s) ...", pkg_names[i], pkg_versions[i]);
            current_step++;
            draw_apt_progress(current_step, total_dpkg_steps, op_buf);
            
            int install_delay = (60 + (pkg_sizes[i] / 10)) * 1.2;
            msleep(install_delay); 
        }

        printf("\r\033[KProcessing triggers for libc-bin (%s) ...\n", pkg_versions[0]);
        msleep(600);
        printf("\r\033[KProcessing triggers for man-db (%s) ...\n", pkg_versions[1]);
        msleep(960);

        // SUCCESS / ERROR STAGE
        if (rand() % 100 < 15) { 
            int err_idx = rand() % pkg_count;
            printf("\r\033[K\n%s[FATAL]%s dpkg: error processing package %s%s%s (--configure):\n", CLR_RED, CLR_RESET, CLR_WHITE, pkg_names[err_idx], CLR_RESET);
            printf("\r\033[K%s installed %s package post-installation script subprocess returned error exit status 1%s\n", CLR_RED, pkg_names[err_idx], CLR_RESET);
            printf("\r\033[K%sErrors were encountered while processing:%s\n", CLR_YELLOW, CLR_RESET);
            printf("\r\033[K  %s%s%s\n", CLR_CYAN, pkg_names[err_idx], CLR_RESET);
            printf("\r\033[K%sE: Sub-process /usr/bin/dpkg returned an error code (1)%s\n", CLR_RED, CLR_RESET);
            
            // Interactive error recovery simulation
            msleep(800);
            printf("\r\033[K%sAttempt automatic dependency resolution? [Y/n]%s ", CLR_MAGENTA, CLR_RESET);
            fflush(stdout); msleep(1500 + rand() % 1000); // Simulate the user "thinking"
            printf("%sY\n", CLR_RESET);
            
            msleep(600);
            get_time(t);
            printf("\r\033[K%s [%sSYSTEM%s] Rebuilding dpkg journal... %sFailed.%s\n\n", t, CLR_RED, CLR_RESET, CLR_RED, CLR_RESET);
            msleep(6000); 
            
        } else {
            get_time(t);
            printf("\r\033[K\n%s [%sSYSTEM%s] %sAPT transaction successful. Verifying integrity...%s\n", t, CLR_YELLOW, CLR_RESET, CLR_GREEN, CLR_RESET);
            msleep(1500);
            
            // Interactive auto-cleanup simulation
            printf("\r\033[K%sThe following packages were automatically installed and are no longer required:%s\n", CLR_CYAN, CLR_RESET);
            
            // Grab a couple of random names from the word pools for the cleanup fluff
            printf("\r\033[K  %s%s%s %s%s%s\n", 
                   prefixes[rand() % 22], bases[rand() % 40], suffixes[rand() % 18],
                   prefixes[rand() % 22], bases[rand() % 40], suffixes[rand() % 18]);
                   
            msleep(400);
            printf("\r\033[K%sRemove unused dependencies? [Y/n]%s ", CLR_MAGENTA, CLR_RESET);
            fflush(stdout); msleep(1200 + rand() % 800); // Simulate the user hitting 'y'
            printf("%sY\n", CLR_RESET);
            
            msleep(400);
            printf("\r\033[K%s [%sSYSTEM%s] %sPurging orphaned packages... Done.%s\n\n", t, CLR_YELLOW, CLR_RESET, CLR_GREEN, CLR_RESET);
            msleep(4000);
        }
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
    {"crypto",  "Simulates a high-speed multi-GPU cryptocurrency mining rig", module_cryptominer},
    {"proxy",   "High-concurrency proxy scanner with latency testing", module_proxy},
    {"network", "Deep packet inspection firewall logger and TCP/IP hex dumper", module_network},
    {"ml",      "Dynamic ML pipelines with GPU allocation and epoch training", module_ml},
    {"package", "Authentic Debian APT system updates and unpacking", module_package}
};

int num_modules = sizeof(modules) / sizeof(modules[0]);

void print_help(const char *prog_name) {
    printf("Usage: %s <module> [speed]\n\n", prog_name);
    printf("Available modules:\n");
    for (int i = 0; i < num_modules; i++) {
        printf("  %-10s : %s\n", modules[i].name, modules[i].description);
    }
    printf("  %-10s : Pick a random module\n", "random");
}

void print_about() {
    printf("lookbusy - Linux terminal nonsense generator\n");
    printf("Version: %s\n", APP_VERSION);
    printf("Author:  %s\n", APP_AUTHOR);
    printf("Repo:    %s\n", APP_REPO);
    printf("License: MIT\n");
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

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--version") == 0 || strcmp(argv[i], "-v") == 0) {
            printf("lookbusy %s\n", APP_VERSION);
            return 0;
        }
        if (strcmp(argv[i], "--about") == 0 || strcmp(argv[i], "-a") == 0) {
            print_about();
            return 0;
        }
        if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) {
            print_help(argv[0]);
            return 0;
        }
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
        } else if (strcmp(argv[i], "--slow") == 0) {
            speed_factor = 2.0; // 2x slower
        } else if (strcmp(argv[i], "--slower") == 0) {
            speed_factor = 4.0; // 4x slower
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
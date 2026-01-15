# NetPractice

`NetPractice` is a web-based networking training project focused on IP addressing, subnetting, and routing configuration. The project provides interactive network diagrams where you must configure IP addresses, subnet masks, and routing tables to establish proper communication between hosts, routers, and the internet.

This project is an introduction to networking fundamentals, including CIDR notation, subnet calculations, routing rules, and network topology understanding.

I did some networking at University just before doing this project, so it helped me a lot to understand the concepts. Though I didn't really read my lectures, I managed to develop my own logic of the thing as I trained to address the IPs.
Funny project, not difficult and it's really enjoyable to solve the levels one by one.

---

## Prototype

Local web-based training interface accessible through any modern browser.

**How to use:**
```bash
# Clone the repository
git clone <your-repo-url>
cd NetPractice

# Open the main page in your browser
open Levels/index.html        # macOS
xdg-open Levels/index.html    # Linux
start Levels/index.html       # Windows

# Or simply double-click on Levels/index.html
```

**Training modes:**
- Enter bguerrou (or anything really) to access all 10 levels
- Leave empty for defense mode: 3 random levels (from 6th to 10th) with a 15-minutes timer

---

## Behavior

- The training presents 10 progressive levels with increasing complexity.
- Each level displays a network diagram with:
  - **Hosts** (computers/clients) labeled A, B, C, D, H1, H2, etc.
  - **Routers** labeled R1, R2, etc.
  - **Switches** labeled S1, S2, etc.
  - **Internet** gateway (labeled I or Internet)
  
- The task is to fill in the missing network configuration:
  - **IP addresses** for network interfaces
  - **Subnet masks** (in decimal or CIDR notation)
  - **Default gateways** for routing
  - **Static routes** for complex topologies

- The interface validates your configuration in real-time:
  - ✅ Green checkmark: Configuration is correct
  - ❌ Red cross: Configuration has errors
  - Grey fields: Pre-configured (cannot be modified)
  - White fields: Must be filled in

---

## Concepts

### IP Addressing
- **IPv4 format:** 4 octets (8 bits each) → `192.168.1.1`
- Each octet ranges from 0 to 255

### Subnet Masks
- Determines which portion of an IP is the network vs host
- **Format:** Decimal (`255.255.255.0`) or CIDR (`/24`)
- Common masks:
  - `/24` = `255.255.255.0` → 256 addresses (254 usable)
  - `/25` = `255.255.255.128` → 128 addresses (126 usable)
  - `/26` = `255.255.255.192` → 64 addresses (62 usable)
  - `/27` = `255.255.255.224` → 32 addresses (30 usable)
  - `/28` = `255.255.255.240` → 16 addresses (14 usable)
  - `/30` = `255.255.255.252` → 4 addresses (2 usable, typically for point-to-point)

### Routing
- **Default route:** `0.0.0.0/0` or `default` → sends all non-local traffic to a gateway
- **Static routes:** Specific routes for particular networks
- **Gateway:** The router's IP address on the local network

### Subnetting Example
If you have `192.168.1.0/24`:
- Network: `192.168.1.0`
- Usable IPs: `192.168.1.1` to `192.168.1.254`
- Broadcast: `192.168.1.255`
- Subnet mask: `255.255.255.0`

To split into 2 subnets (`/25`):
- Subnet 1: `192.168.1.0/25` (IPs: 1-126)
- Subnet 2: `192.168.1.128/25` (IPs: 129-254)

---

## Notes

- This project requires no programming - it's purely theoretical networking knowledge.
- All levels can be accessed locally without an internet connection.
- The interface provides immediate feedback, making it a good learning tool.
- Understanding binary representation of IP addresses helps significantly.
- The JSON files in `Resolution/` can be imported into the web interface to review solutions.
- Configuration rules:
  - Devices on the same network segment must share the same subnet
  - IP addresses within a subnet must be unique
  - Hosts need a default gateway to reach other networks
  - Routers need routing tables to forward packets
  - Private IP ranges: 10.0.0.0/8, 172.16.0.0/12, 192.168.0.0/16
  - The first IP in a subnet is the network address (unusable)
  - The last IP in a subnet is the broadcast address (unusable)

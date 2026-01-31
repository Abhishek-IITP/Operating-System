# 🚀 How Operating System Boots Up?

Booting is the process of **starting the computer and loading the Operating System into memory**.

---

## 🥇 Step 1: Power On

- User presses the **Power Button**
- Power Supply (SMPS) starts supplying power to:
  - Motherboard
  - CPU
  - RAM
  - Storage devices (HDD / SSD)

---

## 🥈 Step 2: CPU Initialization & Firmware Load

- CPU gets power and starts execution
- CPU loads firmware:
  - **BIOS** (older systems)
  - **UEFI** (modern systems)
- Firmware code is stored on a **chip on motherboard**

> CPU always starts execution from a fixed memory address where BIOS/UEFI is stored.

---

## 🥉 Step 3: POST (Power On Self Test)

- BIOS / UEFI performs **POST**
- It checks whether hardware is working properly or not:
  - RAM
  - Keyboard
  - CPU
  - Storage devices

- BIOS / UEFI loads system configuration:
  - From **CMOS memory**
  - CMOS is powered by a small **CMOS battery**

> If POST fails → system may beep or not boot.

---

## 🏅 Step 4: Boot Device Selection

- BIOS / UEFI decides **boot device order**:
  - HDD / SSD
  - USB
  - CD/DVD
  - Network (PXE)

### Boot Record Loading

#### 🔹 BIOS Based Systems
- Uses **MBR (Master Boot Record)**
- MBR is located at:
  - **0th sector of the disk**
- MBR contains:
  - Bootloader location
  - Partition table
- Used in **older systems**

#### 🔹 UEFI Based Systems
- Uses **EFI System Partition (ESP)**
- ESP is a **separate partition** on disk
- Stores bootloader files
- Used in **modern systems**

---

## 🥉 Step 5: Boot Loader Execution

- Bootloader is a small program that:
  - Loads the OS kernel into RAM
  - Transfers control to OS

### Common Boot Loaders
- **Windows** → `bootmgr.exe`
- **Linux** → `GRUB`
- **macOS** → `boot.efi`

---

## 🏁 Step 6: OS Kernel Initialization

- Bootloader loads **OS Kernel** into memory
- Kernel:
  - Initializes hardware drivers
  - Starts system services
  - Creates first user-space process
- Finally, user sees:
  - Login screen
  - Desktop / CLI

---

## 🔁 Boot Process Summary (Flow)

Power ON

↓

CPU starts

↓

BIOS / UEFI loads

↓

POST (Hardware Check)

↓

Boot Device Selection

↓

MBR / EFI

↓

Boot Loader

↓

Kernel Loaded

↓

Operating System Ready

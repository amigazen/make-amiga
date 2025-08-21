## Building from Source

### Requirements
- SAS/C compiler 6.58
- NDK
- ToolKit including Make, or use the Make binary from SDK/C/Make in this distribution

### Build Commands
```bash
; Using Basic.mk not SMakefile
cd Source/
make -f Basic.mk
copy make /SDK/C/make ;Copy Codex to the SDK/C drawer in the project directory, or copy to wherever you want it
```

## Installation

1. Find the make executable in SDK/C/ in this distribution

# Dependencies

```
sudo apt install llvm lld-14
```

# Build WASM

```
clang --target=wasm32 --no-standard-libraries -Wl,--export-all -Wl,--no-entry -o add.wasm add.c
```

# Run

```
python3 -m http.server  
```

# VarySize

Use the following instructions to install various sizes of
firmware binary:

```
git clone https://github.com/StratifyLabs/VarySize.git
sl app.build:path=VarySize
sl app.install:path=VarySize,build=size256k
sl app.run:path=VarySize,terminal
```

Other sizes are documented in CMakeLists.txt.


from pathlib import Path
import json

FLAGS = [
    "clang",
    "-std=c23",
    "-Wall",
    "-Wextra",
    "-Wpedantic",
    "-g"
]

entries = []

for file in Path(".").rglob("*.c"):
    entries.append(
        {
            "directory": str(Path.cwd()),
            "command": " ".join(FLAGS + [str(file)]),
            "file": str(file)
        }
    )

with open("compile_commands.json", "w") as f:
    json.dump(entries, f, indent=2)

print("compile_commands.json generated")
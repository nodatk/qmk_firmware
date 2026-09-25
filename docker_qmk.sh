#!/bin/sh
# Runs the `qmk` CLI inside the official ghcr.io/qmk/qmk_cli Docker image,
# with this repo mounted at /qmk_firmware -- for building without installing
# the ARM toolchain locally.
#
# Usage (from the qmk_firmware root):
#   ./docker_qmk.sh compile -kb handwired/twig/twig8 -km default
#   ./docker_qmk.sh flash -kb handwired/twig/twig8 -km default
#
# Requires Docker Desktop running (`open -a Docker` on macOS if it isn't).

set -e

docker run --rm \
	--user "$(id -u):$(id -g)" \
	-w /qmk_firmware \
	-v "$(pwd)":/qmk_firmware:z \
	ghcr.io/qmk/qmk_cli \
	qmk "$@"

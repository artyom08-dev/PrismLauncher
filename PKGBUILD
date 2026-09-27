# Maintainer: artyom08-dev
# Based on the Arch Linux extra/prismlauncher PKGBUILD

pkgname=prismlauncher-git
pkgver=11.0.3
pkgrel=1
pkgdesc="Minecraft launcher with ability to manage multiple instances (fork with offline accounts)"
arch=('x86_64')
url='https://github.com/artyom08-dev/PrismLauncher'
license=('GPL-3.0-only AND LGPL-3.0-or-later AND LGPL-2.0-or-later AND Apache-2.0 AND MIT AND OFL-1.1')
provides=('prismlauncher')
conflicts=('prismlauncher')
depends=(
  glibc
  mesa-utils
  libarchive
  libgl
  pciutils
  qrencode
  qt6-base
  qt6-imageformats
  qt6-networkauth
  qt6-svg
  zlib
  hicolor-icon-theme
  tomlplusplus
  cmark
  libstdc++
  libgcc
)
makedepends=(
  cmake
  extra-cmake-modules
  git
  jdk17-openjdk
  ninja
  scdoc
  gamemode
  vulkan-headers
)
optdepends=(
  'glfw: to use system GLFW libraries'
  'openal: to use system OpenAL libraries'
  'visualvm: profiling support'
  'xorg-xrandr: for older minecraft versions'
  'java-runtime: use system java versions'
)
source=("$pkgname::git+https://github.com/artyom08-dev/PrismLauncher.git")
b2sums=('SKIP')

pkgver() {
  cd "$srcdir/$pkgname"
  ( git describe --long 2>/dev/null | sed 's/^v//;s/\([^-]*-g\)/r\1/;s/-/./g' ) ||
    printf "r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short HEAD)"
}

build() {
  export PATH="/usr/lib/jvm/java-17-openjdk/bin/:$PATH"

  local cmake_options=(
    -B build
    -S "$srcdir/$pkgname"
    -G Ninja
    -D Launcher_BUILD_PLATFORM=archlinux
    -D Launcher_ENABLE_JAVA_DOWNLOADER=ON
    -W no-dev
    -D CMAKE_BUILD_TYPE=None
    -D CMAKE_INSTALL_PREFIX=/usr
  )

  cmake "${cmake_options[@]}"
  cmake --build build
}

check() {
  ctest --test-dir build
}

package() {
  install -Dm644 "$srcdir/$pkgname/COPYING.md" -t "$pkgdir/usr/share/licenses/$pkgname/"

  DESTDIR="$pkgdir" cmake --install build
}

# vim:set ts=2 sw=2 et:

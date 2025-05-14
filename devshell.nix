{
  inputs,
  system,
  perSystem,
  ...
}:
let
  pkgs = import inputs.nixpkgs {
    inherit system;
    overlays = [ (import inputs.rust-overlay) ];
  };
  llvm = pkgs.llvmPackages_19;
  toolchain = pkgs.rust-bin.fromRustupToolchainFile ./rust-toolchain.toml;
in
pkgs.mkShell {
  # Add build dependencies
  packages = [
    toolchain
    pkgs.python314
    pkgs.boost
    pkgs.clang-tools
    llvm.clang
    llvm.lldb
    llvm.libllvm

    perSystem.cp-tools.default
    perSystem.cp-tools.extra
  ];

  # Add environment variables
  env = { };

  # Load custom bash code
  shellHook = ''

  '';
}

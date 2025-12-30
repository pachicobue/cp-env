{
  system,
  inputs,
}: let
  pkgs = import inputs.nixpkgs {
    inherit system;
  };
  llvm = pkgs.llvmPackages_latest;
  clangd-wrapped = pkgs.writeShellScriptBin "clangd" ''
    exec ${llvm.clang-tools}/bin/clangd \
      --query-driver="$(echo ${llvm.clang}/bin/clang++)" \
      "$@"
  '';
  cpt = inputs.cp-tools.outputs.packages.${system};
in {
  default = pkgs.mkShell {
    packages = [
      pkgs.python3Minimal
      pkgs.boost
      llvm.clang-tools
      llvm.clang
      llvm.lldb
      llvm.libllvm

      clangd-wrapped

      cpt.default
      cpt.extra
    ];
    shellHook = ''
      alias clangd='${llvm.clang-tools}/bin/clangd --query-driver=$(which clang++)'
      echo "clangd wrapper loaded with query-driver support"
    '';
  };
}

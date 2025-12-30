{
  description = "競技プログラミング用スペース (C++)";

  inputs = {
    nixpkgs.url = "nixpkgs";
    flake-utils.url = "github:numtide/flake-utils";
    cp-tools.url = "github:pachicobue/cp-tools";
  };

  outputs = {flake-utils, ...} @ inputs:
    flake-utils.lib.eachDefaultSystem (
      system: let
        args = {
          inherit inputs;
          inherit system;
        };
      in {
        # nixosConfigurations = import ./nixos-configuration.nix args;
        # packages = import ./package.nix args;
        # checks = import ./check.nix args;
        devShells = import ./devshell.nix args;
      }
    );
}

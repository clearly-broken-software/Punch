declare name      "CharacterCompressor";
declare author    "Bart Brouns";
declare version   "0.3.3";
declare copyright "(C) 2014 Bart Brouns";

import("lib/CharacterCompressor.lib");

process =
  // ba.bypass2(checkbox("bypass"),midStereoBlushComp);
  // midStereoBlushComp;
  blushcompN(2);

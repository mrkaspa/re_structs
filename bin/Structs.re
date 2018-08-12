open Lib;
open Core;

let _ = {
  /*  Using Maps */
  let map = Util.make_int_map([(1, "uno"), (2, "dos")]);
  let tree = Map.to_tree(map);
  let valueOpt = Map.Tree.find(~comparator=Int.comparator, tree, 1);
  Util.print_value(valueOpt);

  /* Using Sets */
  let ls = [2, 2, 1, 2, 4, 5, 4, 3];
  let dd = Util.dedup((module Int), ls);
  List.iter(dd, ~f=n => print_string("- " ++ string_of_int(n) ++ "\n"));

  /* Custom Comparable */
  print_string("Custom >> " ++ string_of_bool(Util.cmp2()) ++ "\n");
};

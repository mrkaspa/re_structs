open Core;

let dedup = (comparator, ls) =>
  ls |> List.fold(~init=Set.empty(comparator), ~f=Set.add) |> Set.to_list;

let make_int_map = ls => Map.of_alist_exn((module Int), ls);

let print_value =
  fun
  | Some(value) => print_string("Cad = " ++ value ++ "\n")

  | None => print_string("Not found\n");

open Core;

let dedup = (comparator, ls) =>
  ls |> List.fold(~init=Set.empty(comparator), ~f=Set.add) |> Set.to_list;

let make_int_map = ls => Map.of_alist_exn((module Int), ls);

let print_value =
  fun
  | Some(value) => print_string("Cad = " ++ value ++ "\n")
  | None => print_string("Not found\n");

module Foo_and_bar: {
  type t = {
    foo: Int.Set.t,
    bar: string,
  };
  include Comparable.S with type t := t;
} = {
  module T = {
    [@deriving (sexp, compare)] type t = {
      foo: Int.Set.t,
      bar: string,
    };
  };
  include T;
  include Comparable.Make(T);
};

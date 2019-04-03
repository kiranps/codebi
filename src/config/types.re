type state = {code: string};

type action =
  | Change(string);

type providerType = {
  state,
  dispatch: action => unit,
};
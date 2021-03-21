type state = {
    counter: int 
}

type action =
  | Increment
  | Decrement

let str = React.string;

[@react.component]
let make = () => {
    let ({counter}, dispatch) = React.useReducer((state, action) => {
        switch action {
        | Increment => {counter: state.counter + 1}
        | Decrement => {counter: state.counter - 1}
        }
    }, {
        counter: 0
    });
    <div>
        <div>(str(string_of_int(counter)))</div>
        <button onClick=((_e) => dispatch(Increment))>(str("+"))</button>
        <button onClick=((_e) => dispatch(Decrement))>(str("-"))</button>
    </div>
}
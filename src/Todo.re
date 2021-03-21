type item = {
    id: int,
    title: string,
    completed: bool
}
type state = {
    items: list(item)
}
type action = 
  | AddItem
let str = React.string;

module TodoItem = {
    [@react.component]
    let make = (~item) => {
        <div className="item">
            <input 
                type_="checkbox"
                checked=(item.completed)
            />
            (str(item.title))
        </div>
    }
};

let lastId = ref(0);
let newItem = () => {
        lastId := lastId^ + 1;
    {   
        id: lastId^,
        title: "Clicked a btn",
        completed: true
    }
    
};

[@react.component]
let make = () => {
    let ({items}, dispatch) = React.useReducer((state, action) => {
        switch action {
        | AddItem => {items: [newItem(), ...state.items]}
        };
    }, {
        items: [
            {   id: 0,
                title: "Item 1",
                completed: false
            }
        ]
    });
    let numItems = List.length(items);
    <div className="app">
        <div className="title">
            (str("What to do"))
            <button onClick=((_evt) => dispatch(AddItem))>
            (str("Add something"))
            </button>
        </div>
        <div className="items">
            (
                React.array(Array.of_list(
                    List.map((item) => <TodoItem key=(string_of_int(item.id)) item />, items)
                ))
            )
            /**
             * OR 
             * List.map((item) => <TodoItem item /> ,items) |> Array.of_list |> React.array
             */
        </div>
        <div className="footer">
            (str(string_of_int(numItems) ++ " items"))
        </div>
</div>
}
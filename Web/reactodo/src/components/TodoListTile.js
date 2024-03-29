import React from 'react';

function TodoListTile(prop){
    return (
        <div className='TodoListTile'>
            <h3>{prop.data.text}</h3>
            <input type="checkbox" checked={prop.data.completed ? true : false}></input>            
        </div>
    );
}


export default TodoListTile;
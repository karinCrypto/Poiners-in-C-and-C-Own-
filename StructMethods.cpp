struct Dog {
    name: String,
    age: u8,
}

impl Dog {
    fn bark(&self) {
        println!("{}: woof!", self.name);
    }
}

fn main() {
    let d = Dog { name: "Coco".into(), age: 3 };
    d.bark();
}
